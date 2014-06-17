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
  $display->layout = 'openstack_front';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'os_top' => NULL,
      'os_left' => NULL,
      'os_center' => NULL,
      'os_right' => NULL,
      'os_middle' => NULL,
      'os_bottom_left' => NULL,
      'os_bottom_right' => NULL,
      'os_bottom' => NULL,
      'two_66_33_top' => NULL,
      'two_66_33_first' => NULL,
      'two_66_33_second' => NULL,
      'two_66_33_bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Groups Home';
  $display->uuid = '7a0357d1-bf3b-54e4-b522-6c15eedf8a93';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b2494b76-fb10-46c5-bc6a-e6fec2d3919e';
    $pane->panel = 'os_bottom_left';
    $pane->type = 'panels_ajax_tab_tabs';
    $pane->subtype = 'panels_ajax_tab_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'mini_panels' => array(
        'upcoming_events' => array(
          'selected' => 1,
          'tab_title' => '',
          'url_id' => '',
          'weight' => '-10',
        ),
        'recent_activity' => array(
          'selected' => 1,
          'tab_title' => '',
          'url_id' => '',
          'weight' => '-9',
        ),
      ),
      'container_id' => 'front-events-activity-container',
      'url_enabled' => 1,
      'context' => array(
        0 => 'empty',
      ),
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
    $pane->uuid = 'b2494b76-fb10-46c5-bc6a-e6fec2d3919e';
    $display->content['new-b2494b76-fb10-46c5-bc6a-e6fec2d3919e'] = $pane;
    $display->panels['os_bottom_left'][0] = 'new-b2494b76-fb10-46c5-bc6a-e6fec2d3919e';
    $pane = new stdClass();
    $pane->pid = 'new-f29e6e7e-d5c9-4bfd-b2b8-22769d9b8d8e';
    $pane->panel = 'os_bottom_left';
    $pane->type = 'panels_ajax_tab_container';
    $pane->subtype = 'panels_ajax_tab_container';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'container_id' => 'front-events-activity-container',
      'context' => array(
        0 => 'empty',
      ),
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f29e6e7e-d5c9-4bfd-b2b8-22769d9b8d8e';
    $display->content['new-f29e6e7e-d5c9-4bfd-b2b8-22769d9b8d8e'] = $pane;
    $display->panels['os_bottom_left'][1] = 'new-f29e6e7e-d5c9-4bfd-b2b8-22769d9b8d8e';
    $pane = new stdClass();
    $pane->pid = 'new-7ae087d4-887e-4b54-b980-44fb87245089';
    $pane->panel = 'os_bottom_right';
    $pane->type = 'block';
    $pane->subtype = 'groups_homepage-groups_community_stats';
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
    $pane->uuid = '7ae087d4-887e-4b54-b980-44fb87245089';
    $display->content['new-7ae087d4-887e-4b54-b980-44fb87245089'] = $pane;
    $display->panels['os_bottom_right'][0] = 'new-7ae087d4-887e-4b54-b980-44fb87245089';
    $pane = new stdClass();
    $pane->pid = 'new-6b115d65-3d2e-4c7e-ad86-fd17d190afc0';
    $pane->panel = 'os_top';
    $pane->type = 'views';
    $pane->subtype = 'groups_map';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
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
    $pane->uuid = '6b115d65-3d2e-4c7e-ad86-fd17d190afc0';
    $display->content['new-6b115d65-3d2e-4c7e-ad86-fd17d190afc0'] = $pane;
    $display->panels['os_top'][0] = 'new-6b115d65-3d2e-4c7e-ad86-fd17d190afc0';
    $pane = new stdClass();
    $pane->pid = 'new-c2b9e460-b848-d8f4-8153-cf0687afd8ea';
    $pane->panel = 'os_top';
    $pane->type = 'block';
    $pane->subtype = 'groups_homepage-groups_find_nearby';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c2b9e460-b848-d8f4-8153-cf0687afd8ea';
    $display->content['new-c2b9e460-b848-d8f4-8153-cf0687afd8ea'] = $pane;
    $display->panels['os_top'][1] = 'new-c2b9e460-b848-d8f4-8153-cf0687afd8ea';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['groups_home'] = $page;

  return $pages;

}
