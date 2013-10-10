<?php

/**
 * Define minimum execution time required to operate.
 */
define('DRUPAL_MINIMUM_MAX_EXECUTION_TIME', 120);

/**
 * Implements hook_admin_paths_alter().
 */
function groups_admin_paths_alter(&$paths) {
  // Avoid switching between themes when users edit their account.
  $paths['user'] = FALSE;
  $paths['user/*'] = FALSE;
}

/**
 * Implements hook_install_tasks_alter().
 */
function groups_install_tasks_alter(&$tasks, $install_state) {
  global $install_state;

  // Skip profile selection step.
  $tasks['install_select_profile']['display'] = FALSE;

  // Skip language selection install step and default language to English.
  $tasks['install_select_locale']['display'] = FALSE;
  $tasks['install_select_locale']['run'] = INSTALL_TASK_SKIP;
  $install_state['parameters']['locale'] = 'en';

  // Override "install_finished" task to redirect people to home page.
  $tasks['install_finished']['function'] = 'groups_install_finished';
}

/**
 * Implements hook_install_tasks().
 *
 * Allows the user to set a welcome message for anonymous users
 */
function groups_install_tasks() {
  // Suppress any status messages generated during batch install.
  groups_clear_messages();

  //make sure we have more memory than 196M. if not lets try to increase it.
  if (ini_get('memory_limit') != '-1' && ini_get('memory_limit') <= '196M' && ini_get('memory_limit') >= '128M') {
    ini_set('memory_limit', '196M');
  }

  $demo_content = variable_get('groups_install_example_content', TRUE);

  return array(
    'groups_revert_features' => array(
      'display' => FALSE,
    ),
    'groups_demo_content' => array(
      'display' => FALSE,
      'type' => '',
      'run' => $demo_content ? INSTALL_TASK_RUN_IF_NOT_COMPLETED : INSTALL_TASK_SKIP,
    ),
/*
 * NOTICE: disabled due groups-dev mysql performance issue
 *   'groups_import_locales' => array(
 *     'display_name' => 'Install additional languages',
 *     'display' => TRUE,
 *     'type' => 'batch',
 *     'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
 *   ),
 */
  );
}

/**
 * Import translation files and languages from profile directory
 *
 */
function groups_import_locales(&$install_state) {
  include_once DRUPAL_ROOT . '/includes/locale.inc';
  include_once DRUPAL_ROOT . '/includes/iso.inc';

  $batch = array(
    'title' => t('Importing interface translations'),
    'init_message' => t('Starting import'),
    'error_message' => t('Error importing interface translations'),
    'file' => 'includes/locale.inc',
    'operations' => array(),
  );

  $predefined = _locale_get_predefined_list();
  $path = drupal_get_path('profile', drupal_get_profile()) . '/translations';
  $translations = file_scan_directory($path, '/.*\.po$/');
  foreach ($translations as $file) {
    $langcode = pathinfo($file->name, PATHINFO_EXTENSION);
    if (isset($predefined[$langcode])) {
      locale_add_language($langcode);
      $batch['operations'][] = array('_locale_import_po', array($file,
        $langcode, LOCALE_IMPORT_OVERWRITE, 'default'));
    }
  }

  return $batch;
}

/**
 * Set language negotiation to URL based.
 *
 */
function groups_set_language_negotiation() {
  require_once DRUPAL_ROOT . '/includes/language.inc';
  require_once DRUPAL_ROOT . '/includes/locale.inc';
  $negotation = array(
    LOCALE_LANGUAGE_NEGOTIATION_URL => 2,
    LANGUAGE_NEGOTIATION_DEFAULT => 10,
  );
  language_negotiation_set(LANGUAGE_TYPE_INTERFACE, $negotation);
}

/**
 * Override of install_finished() without the useless text.
 */
function groups_install_finished(&$install_state) {
  // BEGIN copy/paste from install_finished().
  // Remove the bookmarks flag
  include_once DRUPAL_ROOT . '/profiles/groups/modules/contrib/flag/includes/flag.admin.inc';
  $flag = flag_get_flag('bookmarks');
  if($flag) {
    $flag->delete();
    $flag->disable();
    _flag_clear_cache();
  }

  // set language negotation
  groups_set_language_negotiation();

  // Flush all caches to ensure that any full bootstraps during the installer
  // do not leave stale cached data, and that any content types or other items
  // registered by the installation profile are registered correctly.
  drupal_flush_all_caches();

  // Remember the profile which was used.
  variable_set('install_profile', drupal_get_profile());

  // Installation profiles are always loaded last
  db_update('system')
    ->fields(array('weight' => 1000))
    ->condition('type', 'module')
    ->condition('name', drupal_get_profile())
    ->execute();

  // Cache a fully-built schema.
  drupal_get_schema(NULL, TRUE);

  // Run cron to populate update status tables (if available) so that users
  // will be warned if they've installed an out of date Drupal version.
  // Will also trigger indexing of profile-supplied content or feeds.
  drupal_cron_run();
  // END copy/paste from install_finished().

  if (isset($messages['error'])) {
    $output = '<p>' . (isset($messages['error']) ? st('Review the messages above before visiting <a href="@url">your new site</a>.', array('@url' => url(''))) : st('<a href="@url">Visit your new site</a>.', array('@url' => url('')))) . '</p>';
    return $output;
  }
  else {
    // Since any module can add a drupal_set_message, this can bug the user
    // when we redirect him to the front page. For a better user experience,
    // remove all the message that are only "notifications" message.
    groups_clear_messages();
    // If we don't install drupal using Drush, redirect the user to the front
    // page.
    if (!drupal_is_cli()) {
      drupal_goto('');
    }
  }
}

/*
 * Revert Features after the installation.
 */
function groups_revert_features() {
  // Revert Features components to ensure that they are in their default states.
  $revert = array(
    'commons_groups' => array('field_instance'),
    'commons_trusted_contacts' => array('field_instance'),
    'commons_wikis' => array('og_features_permission'),
    'commons_wysiwyg' => array('user_permission', 'ckeditor_profile'),
  );
  features_revert($revert);
}

/**
 * Clear all 'notification' type messages that may have been set.
 */
function groups_clear_messages() {
  drupal_get_messages('status', TRUE);
  drupal_get_messages('completed', TRUE);
  // Migrate adds its messages under the wrong type, see #1659150.
  drupal_get_messages('ok', TRUE);
}

/**
 * Create demo group
 */
function groups_demo_create_group($title, $location) {
  $group = new stdClass();
  $group->type = 'group';
  node_object_prepare($group);
  $group->title = $title;
  $group->body[LANGUAGE_NONE][0]['value'] = 'Lorem ipsum...';
  $group->uid = 1;
  $group->language = LANGUAGE_NONE;
  $group->created = time() - 604800;
  $group->status = 1;
  $group->field_group_location[LANGUAGE_NONE][0] = $location;
  return $group;
}

/**
 * Demo content
 */
function groups_demo_groups() {
  return array(
    // EU Groups
    array(
      'title' => 'Switzerland',
      'location' => array('country' => 'CH','continent' => 'EU',
        'lat' => '46.818188','lng' => '8.227512'),
    ),
    array(
      'title' => 'Hungary',
      'location' => array('country' => 'HU','continent' => 'EU',
        'location' => 'Budapest', 'lat' => '47.497912','lng' => '19.040235'),
    ),
    array(
      'title' => 'Czech Republic',
      'location' => array('country' => 'CZ','continent' => 'EU',
        'location' => 'Prague', 'lat' => '50.0755381','lng' => '14.4378005'),
    ),
    array(
      'title' => 'Italy',
      'location' => array('country' => 'IT','continent' => 'EU',
        'lat' => '41.87194','lng' => '12.56738'),
    ),
    array(
      'title' => 'France',
      'location' => array('country' => 'FR','continent' => 'EU',
        'lat' => '46.227638','lng' => '2.213749'),
    ),
    array(
      'title' => 'Germany',
      'location' => array('country' => 'DE','continent' => 'EU',
        'location' => 'Berlin', 'lat' => '52.519171','lng' => '13.4060912'),
    ),
    // North America Groups
    array(
      'title' => 'Atlanta',
      'location' => array('country' => 'US','continent' => 'NA',
        'location' => 'Atlanta, GA', 'lat' => '33.7489954','lng' => '-84.3879824'),
    ),
    array(
      'title' => 'Austin',
      'location' => array('country' => 'US','continent' => 'NA',
        'location' => 'Austin, TX', 'lat' => '30.267153','lng' => '-97.7430608'),
    ),
    array(
      'title' => 'San Francisco',
      'location' => array('country' => 'US','continent' => 'NA',
        'location' => 'San Francisco, CA', 'lat' => '37.7749295','lng' => '-122.4194155'),
    ),
    array(
      'title' => 'Boston',
      'location' => array('country' => 'US','continent' => 'NA',
        'location' => 'Boston, MA', 'lat' => '42.3584308','lng' => '-71.0597732'),
    ),
    array(
      'title' => 'Canada',
      'location' => array('country' => 'CA','continent' => 'NA',
        'location' => 'Toronto', 'lat' => '43.653226','lng' => '-79.3831843'),
    ),
    // Asia, Pacific groups
    array(
      'title' => 'Australia',
      'location' => array('country' => 'AU','continent' => 'OC',
        'lat' => '-25.274398','lng' => '133.775136'),
    ),
    array(
      'title' => 'Singapore',
      'location' => array('country' => 'SG','continent' => 'AS',
        'lat' => '1.352083','lng' => '103.819836'),
    ),
    array(
      'title' => 'Hong Kong',
      'location' => array('country' => 'HK','continent' => 'AS',
        'lat' => '22.396428','lng' => '114.109497'),
    ),
    array(
      'title' => 'Japan',
      'location' => array('country' => 'JP','continent' => 'AS',
        'lat' => '35.6894875','lng' => '139.6917064'),
    ),
    // Latin America Groups
    array(
      'title' => 'Argentina',
      'location' => array('country' => 'AR','continent' => 'SA',
        'lat' => '-38.416097','lng' => '-63.616672'),
    ),
    array(
      'title' => 'Brazil',
      'location' => array('country' => 'BR','continent' => 'SA',
        'lat' => '-14.235004','lng' => '-51.92528'),
    ),
  );
}

/**
 * This function generate a demo content
 */
function groups_demo_content() {
  // Reset the Flag cache.
  flag_get_flags(NULL, NULL, NULL, TRUE);
  $groups = groups_demo_groups();
  foreach ($groups as $group) {
    $node = groups_demo_create_group($group['title'], $group['location']);
    node_save($node);
  }
}
