<?php

/**
 * @file
 * Groups portal feed import commands.
 *
 */

/**
 * Implementation of hook_drush_help()
 */
function groups_feeds_drush_help($section) {
  switch ($section) {
    case 'meta:dsd:title':
      return dt('Groups portal feed import commands');
    case 'meta:dsd:summary':
      return dt('Import feeds programatically.');
  }
}

/**
 * Implementation of hook_drush_command()
 */
function groups_feeds_drush_command() {
  $items['import-meetup-events'] = array(
    'description' => 'Import meetup.com user group events.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'arguments' => array(),
  );
  $items['import-static-pages'] = array(
    'description' => 'Import static pages.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'arguments' => array(),
  );
  $items['import-user-groups'] = array(
    'description' => 'Import user groups',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'arguments' => array(),
  );
  $items['import-meetup'] = array(
    'description' => 'Import meetup data',
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
function drush_groups_feeds_import_meetup_events() {
  // execute meetup_events_import schedule job
  module_load_include('inc', 'groups_feeds', 'includes/groups_feeds_meetup_events');
  groups_feeds_meetup_events_import(NULL);
}

/**
 * Trigger static pages import.
 */
function drush_groups_feeds_import_static_pages() {
  // execute static_pages_import schedule job
  module_load_include('inc', 'groups_feeds', 'includes/groups_feeds_static_pages');
  groups_feeds_static_pages_import(NULL);
}

/**
 * Trigger groups.json import
 */
function drush_groups_feeds_import_user_groups() {
  module_load_include('inc', 'groups_feeds', 'includes/groups_feeds_user_groups');
  groups_feeds_user_groups_import(NULL);
}

/**
 * Trigger meetup group data import
 */
function drush_groups_feeds_import_meetup() {
  module_load_include('inc', 'groups_feeds', 'includes/groups_feeds_meetup_groups');
  groups_feeds_meetup_import();
}