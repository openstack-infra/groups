<?php

/**
 * Define minimum execution time required to operate.
 */
define('DRUPAL_MINIMUM_MAX_EXECUTION_TIME', 120);

/**
 * Implements hook_hook_info().
 *
 * Provide commons_entity_integration hooks, load hooks from
 * modulename.commons.inc file.
 */
function groups_hook_info() {
  $hooks = array(
    'commons_entity_integration',
    'commons_entity_integration_alter',
  );
  return array_fill_keys($hooks, array('group' => 'commons'));
}

/**
 * Get Commons entity integration information.
 *
 * @param $entity_type
 *   (optional) The entity type to load, e.g. node or user.
 *
 * @return
 *   An associative array of entity integrations whose keys define the entity
 *   type for each integration and whose values contain the bundles which have
 *   been integrated. Each bundle is itself an associative array, whose keys
 *   define the type of integration to enable and whose values contain the
 *   status of the integration. TRUE = enabled, FALSE = disabled.
 */
function commons_entity_integration_info($entity_type = NULL) {
  $info = &drupal_static(__FUNCTION__);
  if (!$info) {
    $info = module_invoke_all('commons_entity_integration');
    drupal_alter('commons_entity_integration', $info);
  }
  if ($entity_type) {
    return isset($info[$entity_type]) ? $info[$entity_type] : array();
  }
  else {
    return $info;
  }
}

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
  $negotiation = array(
    LOCALE_LANGUAGE_NEGOTIATION_URL => 2,
    LANGUAGE_NEGOTIATION_DEFAULT => 10,
  );
  language_negotiation_set(LANGUAGE_TYPE_INTERFACE, $negotiation);
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

  // set language negotiation
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

function field_property_list_reverse_lookup() {
  return array(
      'website' => 0,
      'irc' => 1,
      'twitter' => 2,
      'blog' => 4,
      'meetup' => 5,
      'google-groups' => 6,
      'linkedin' => 7,
      'facebook' => 9,
      'facebook-group' => 10,
      'forum' => 11,
      'email' => 12,
      'calendar' => 13,
      'weibo' => 14,
      'slideshare' => 15,
      'mailing-list' => 16,
      'launchpad' => 17,
      'google-plus' => 18
  );
}

/**
 * Create demo group
 */
function groups_demo_create_group($title, $location, $attributes = null) {
  static $list_lookup;
  if ($list_lookup == null) {
    $list_lookup = field_property_list_reverse_lookup();
  }
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
  if (isset($attributes)) {
    $attr = array();
    foreach ($attributes as $attribute) {
      $key = key($attribute);
      $value = $attribute[$key];
      $attr[] = array(
        'key' => $list_lookup[$key],
        'value' => $value
      );
    }
    $group->field_resource_links['und'] = $attr;
  }
  return $group;
}

/*
 * Create event node.
*/

function groups_demo_create_event($title, $date_from, $date_to = NULL,
    $location) {
  $event = new stdClass();
  $event->type = 'event';
  $event->uid = 1;
  $event->language = LANGUAGE_NONE;
  $event->created = time() - 604800;
  $event->status = 1;
  $event->title = $title;
  $event->body[LANGUAGE_NONE][0]['value'] = 'Lorem ipsum...';
  list($country, $locality, $postal_code, $street_address) = explode('/', $location);
  $event->field_address[LANGUAGE_NONE][0] = array(
      'element_key' => 'node|event|field_address|und|0',
      'thoroughfare' => $street_address,
      'postal_code' => $postal_code,
      'locality' => $locality,
      'country' => $country,
  );
  $event->field_date[LANGUAGE_NONE][0] = array(
      'value' => $date_from,
      'show_todate' => FALSE,
      'timezone' => 'Europe/Berlin',
      'offset' => 3600,
      'offset2' => 3600,
      'timezone_db' => UTC,
      'date_type' => 'datetime',
  );
  if (!empty($date_to)) {
    $event->field_date[LANGUAGE_NONE][0]['value2'] = $date_to;
    $event->field_date[LANGUAGE_NONE][0]['show_todate'] = TRUE;
  }

  $event->field_location[LANGUAGE_NONE][0] = array(
      'value' => 'physical',
  );
  return $event;
}

/**
 * This function generate a demo content
 */
function groups_demo_content() {
  // Reset the Flag cache.
  flag_get_flags(NULL, NULL, NULL, TRUE);
  $groups_raw = file_get_contents(DRUPAL_ROOT . '/profiles/groups/groups.json');
  $groups = json_decode($groups_raw, TRUE);
  foreach ($groups['groups'] as $group) {
    $node = groups_demo_create_group($group['title'], $group['location'],
      $group['attributes']);
    node_save($node);
  }
  // import events
  $events_raw = file_get_contents(DRUPAL_ROOT . '/profiles/groups/events.json');
  $events = json_decode($events_raw, TRUE);
  foreach ($events['events'] as $event) {
    $node = groups_demo_create_event($event['title'], $event['date_from'],
        $event['date_to'], $event['location']);
    node_save($node);
  }
}

/**
 * Set a default user avatar as a managed file object.
 * Load image from file directly instead http download.
 */
function groups_set_default_avatar() {
  global $base_url;
  $picture_directory =  file_default_scheme() . '://' . variable_get('user_picture_path', 'pictures');
  if(file_prepare_directory($picture_directory, FILE_CREATE_DIRECTORY)){
    $filename = DRUPAL_ROOT . '/profiles/groups/images/avatars/user-avatar.png';
    $picture_data = file_get_contents($filename);
    $picture_path = file_stream_wrapper_uri_normalize($picture_directory . '/picture-default.jpg');
    $picture_file = file_save_data($picture_data, $picture_path, FILE_EXISTS_REPLACE);

    // Check to make sure the picture isn't too large for the site settings.
    $validators = array(
        'file_validate_is_image' => array(),
        'file_validate_image_resolution' => array(variable_get('user_picture_dimensions', '85x85')),
        'file_validate_size' => array(variable_get('user_picture_file_size', '30') * 1024),
    );

    // attach photo to user's account.
    $errors = file_validate($picture_file, $validators);
    if (empty($errors)) {
      // Update the user record.
      $picture_file = file_save($picture_file);
      variable_set('user_picture_default', $picture_path);
    }
  }
}
