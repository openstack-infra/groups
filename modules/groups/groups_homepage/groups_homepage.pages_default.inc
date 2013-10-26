<?php
/**
 * @file
 * groups_homepage.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function groups_homepage_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'groups_home';
  $page->task = 'page';
  $page->admin_title = 'Groups Home';
  $page->admin_description = '';
  $page->path = 'home';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Groups Home',
    'weight' => '-20',
    'name' => 'main-menu',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'weight' => 0,
      'name' => 'navigation',
    ),
  );
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_groups_home_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'groups_home';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Landing page',
    'no_blocks' => FALSE,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'two_brick';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'two_brick_top' => NULL,
      'two_brick_left_above' => NULL,
      'two_brick_right_above' => NULL,
      'two_brick_middle' => NULL,
      'two_brick_left_below' => NULL,
      'two_brick_right_below' => NULL,
      'two_brick_bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Groups Home';
  $display->uuid = '7a0357d1-bf3b-54e4-b522-6c15eedf8a93';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1a23fada-1c8b-2cf4-2978-e8aa64e28877';
    $pane->panel = 'two_brick_right_above';
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
    $pane->uuid = '1a23fada-1c8b-2cf4-2978-e8aa64e28877';
    $display->content['new-1a23fada-1c8b-2cf4-2978-e8aa64e28877'] = $pane;
    $display->panels['two_brick_right_above'][0] = 'new-1a23fada-1c8b-2cf4-2978-e8aa64e28877';
    $pane = new stdClass();
    $pane->pid = 'new-4f60b089-fac8-aa14-d1f8-d5674b0d51bc';
    $pane->panel = 'two_brick_right_above';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '4f60b089-fac8-aa14-d1f8-d5674b0d51bc';
    $display->content['new-4f60b089-fac8-aa14-d1f8-d5674b0d51bc'] = $pane;
    $display->panels['two_brick_right_above'][1] = 'new-4f60b089-fac8-aa14-d1f8-d5674b0d51bc';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['groups_home'] = $page;

  return $pages;

}
