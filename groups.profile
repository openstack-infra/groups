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

  return array(
    'groups_revert_features' => array(
      'display' => FALSE,
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


