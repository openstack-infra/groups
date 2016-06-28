<?php

/**
 * @file
 * Groups user profile name migration commands.
 *
 */

 /**
  * Implementation of hook_drush_help()
  */
function groups_oauth2_drush_help($section) {
  switch ($section) {
    case 'meta:dsd:title':
      return dt('Groups portal user profile migration commands');
    case 'meta:dsd:summary':
      return dt('Normalize user profile user names and full names.');
  }
}

/**
 * Implementation of hook_drush_command()
 */
function groups_oauth2_drush_command() {
  $items['migrate-profiles'] = array(
    'description' => 'Migrate user profiles',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'arguments' => array(),
  );
  return $items;
}

/**
 * Trigger meetup event import. Fetch all meetup urls
 * from group node's resource links, and import the ical
 * calendar into event entitites.
 */
function drush_groups_oauth2_migrate_profiles() {
  module_load_include('inc', 'groups_oauth2', 'groups_oauth2.migrate');
  $users = entity_load('user');
  drush_print(dt("Processing user profiles..."));
  foreach ($users as $key => $value) {
    $fullname = _groups_oauth2_normalize_user_name($value);
    if ($fullname != NULL) {
      drush_print(dt('@uid @fullname => @fullnamenew', array(
        '@uid' => $value->uid,
        '@fullname' => $value->data['oauth2_fullname'],
        '@fullnamenew' => $fullname)));
    }
  }
}