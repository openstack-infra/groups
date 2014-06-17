<?php
/**
 * @file
 * groups_homepage.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function groups_homepage_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'recent_activity';
  $mini->category = '';
  $mini->admin_title = 'Recent Activity';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'one';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'one_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1ca209d6-0a3a-4748-9d50-f09e299aae60';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2855799f-fc72-4981-8402-591d13dcd415';
    $pane->panel = 'one_main';
    $pane->type = 'views_panes';
    $pane->subtype = 'commons_activity_streams_activity-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2855799f-fc72-4981-8402-591d13dcd415';
    $display->content['new-2855799f-fc72-4981-8402-591d13dcd415'] = $pane;
    $display->panels['one_main'][0] = 'new-2855799f-fc72-4981-8402-591d13dcd415';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['recent_activity'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'upcoming_events';
  $mini->category = '';
  $mini->admin_title = 'Upcoming Events';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'one';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'one_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '<none>';
  $display->uuid = '291fa2bf-424b-4abd-8408-49fa1805ed44';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b6c08a22-2d0b-4ac5-9e7c-ffe6398d0c1e';
    $pane->panel = 'one_main';
    $pane->type = 'views_panes';
    $pane->subtype = 'commons_events_upcoming-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b6c08a22-2d0b-4ac5-9e7c-ffe6398d0c1e';
    $display->content['new-b6c08a22-2d0b-4ac5-9e7c-ffe6398d0c1e'] = $pane;
    $display->panels['one_main'][0] = 'new-b6c08a22-2d0b-4ac5-9e7c-ffe6398d0c1e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-b6c08a22-2d0b-4ac5-9e7c-ffe6398d0c1e';
  $mini->display = $display;
  $export['upcoming_events'] = $mini;

  return $export;
}
