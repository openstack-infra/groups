<?php
/**
 * @file
 * groups_homepage.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function groups_homepage_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panels_ajax_tab';
  $strongarm->value = array(
    'clean_url' => 0,
    'clean_url_delim' => '/',
    'panes' => array(
      'front-events-activity-container' => array(
        'upcoming_events' => '',
        'recent_activity' => '',
      ),
    ),
  );
  $export['panels_ajax_tab'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_frontpage';
  $strongarm->value = 'home';
  $export['site_frontpage'] = $strongarm;

  return $export;
}
