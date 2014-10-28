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
  $page->admin_description = '';
  $page->path = 'groups';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'User Groups',
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
  $page->conf = array();
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
  $display->layout = 'two_33_66';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'two_33_66_top' => NULL,
      'two_33_66_first' => NULL,
      'two_33_66_second' => NULL,
      'two_33_66_bottom' => NULL,
    ),
    'two_33_66_second' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = 'User Groups';
  $display->uuid = 'B5282991-9D90-4F58-B30F-DB4729DAE4AB';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-261DFD57-3B25-4DFE-8418-5D79026050A0';
    $pane->panel = 'two_33_66_first';
    $pane->type = 'block';
    $pane->subtype = 'groups_directory-groups_directory_filter';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '261DFD57-3B25-4DFE-8418-5D79026050A0';
    $display->content['new-261DFD57-3B25-4DFE-8418-5D79026050A0'] = $pane;
    $display->panels['two_33_66_first'][0] = 'new-261DFD57-3B25-4DFE-8418-5D79026050A0';
    $pane = new stdClass();
    $pane->pid = 'new-11F619FA-9DD0-4710-AAFF-5758ECE3FAA7';
    $pane->panel = 'two_33_66_second';
    $pane->type = 'block';
    $pane->subtype = 'groups_directory-groups_directory_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '11F619FA-9DD0-4710-AAFF-5758ECE3FAA7';
    $display->content['new-11F619FA-9DD0-4710-AAFF-5758ECE3FAA7'] = $pane;
    $display->panels['two_33_66_second'][0] = 'new-11F619FA-9DD0-4710-AAFF-5758ECE3FAA7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-261DFD57-3B25-4DFE-8418-5D79026050A0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['groups_directory'] = $page;

  return $pages;

}
