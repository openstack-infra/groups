<?php
/**
 * @file
 * groups_directory.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function groups_directory_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'groups_directory';
  $page->task = 'page';
  $page->admin_title = 'Groups Directory';
  $page->admin_description = 'A directory of groups.';
  $page->path = 'groups';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Groups',
    'name' => 'main-menu',
    'weight' => '-1',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_groups_directory_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'groups_directory';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Groups',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
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
  $display->title = 'Groups';
  $display->uuid = 'd2985b74-dfbb-8c44-75c5-66561d3f51d9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-36c90f7b-8dc4-8454-ad40-eb1a8c79b542';
    $pane->panel = 'one_main';
    $pane->type = 'views';
    $pane->subtype = 'groups_map';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '36c90f7b-8dc4-8454-ad40-eb1a8c79b542';
    $display->content['new-36c90f7b-8dc4-8454-ad40-eb1a8c79b542'] = $pane;
    $display->panels['one_main'][0] = 'new-36c90f7b-8dc4-8454-ad40-eb1a8c79b542';
    $pane = new stdClass();
    $pane->pid = 'new-a462e99c-3629-0aa4-e15f-4a84115becc7';
    $pane->panel = 'one_main';
    $pane->type = 'views';
    $pane->subtype = 'groups_groups_directory';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a462e99c-3629-0aa4-e15f-4a84115becc7';
    $display->content['new-a462e99c-3629-0aa4-e15f-4a84115becc7'] = $pane;
    $display->panels['one_main'][1] = 'new-a462e99c-3629-0aa4-e15f-4a84115becc7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['groups_directory'] = $page;

  return $pages;

}
