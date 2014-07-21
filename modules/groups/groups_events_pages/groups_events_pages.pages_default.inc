<?php
/**
 * @file
 * groups_events_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function groups_events_pages_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'groups_events_landing_page';
  $page->task = 'page';
  $page->admin_title = 'Groups Events Landing Page';
  $page->admin_description = '';
  $page->path = 'events';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_groups_events_landing_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'groups_events_landing_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'two_66_33';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'two_66_33_top' => NULL,
      'two_66_33_first' => NULL,
      'two_66_33_second' => NULL,
      'two_66_33_bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Events';
  $display->uuid = 'f084cd6c-0d66-7ca4-c971-3c5cf182d2ec';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e72884a7-369b-1954-2d1f-d69207c4d6ff';
    $pane->panel = 'two_66_33_first';
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
    $pane->uuid = 'e72884a7-369b-1954-2d1f-d69207c4d6ff';
    $display->content['new-e72884a7-369b-1954-2d1f-d69207c4d6ff'] = $pane;
    $display->panels['two_66_33_first'][0] = 'new-e72884a7-369b-1954-2d1f-d69207c4d6ff';
    $pane = new stdClass();
    $pane->pid = 'new-9118fc7d-3da5-cf54-5152-5d66043812b2';
    $pane->panel = 'two_66_33_second';
    $pane->type = 'views_panes';
    $pane->subtype = 'commons_events_user_upcoming_events-panel_pane_1';
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
    $pane->uuid = '9118fc7d-3da5-cf54-5152-5d66043812b2';
    $display->content['new-9118fc7d-3da5-cf54-5152-5d66043812b2'] = $pane;
    $display->panels['two_66_33_second'][0] = 'new-9118fc7d-3da5-cf54-5152-5d66043812b2';
    $pane = new stdClass();
    $pane->pid = 'new-ef7caf29-a6a8-e654-5997-6b969eba407a';
    $pane->panel = 'two_66_33_second';
    $pane->type = 'views_panes';
    $pane->subtype = 'commons_events_user_upcoming_events-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'ef7caf29-a6a8-e654-5997-6b969eba407a';
    $display->content['new-ef7caf29-a6a8-e654-5997-6b969eba407a'] = $pane;
    $display->panels['two_66_33_second'][1] = 'new-ef7caf29-a6a8-e654-5997-6b969eba407a';
    $pane = new stdClass();
    $pane->pid = 'new-80f087dc-fe84-7354-e19b-23e398080db9';
    $pane->panel = 'two_66_33_second';
    $pane->type = 'views_panes';
    $pane->subtype = 'commons_events_user_upcoming_events-panel_pane_3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '80f087dc-fe84-7354-e19b-23e398080db9';
    $display->content['new-80f087dc-fe84-7354-e19b-23e398080db9'] = $pane;
    $display->panels['two_66_33_second'][2] = 'new-80f087dc-fe84-7354-e19b-23e398080db9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-9118fc7d-3da5-cf54-5152-5d66043812b2';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['groups_events_landing_page'] = $page;

  return $pages;

}
