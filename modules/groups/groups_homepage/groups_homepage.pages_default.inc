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
      'os_top_left' => NULL,
      'os_top_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Groups Home';
  $display->uuid = '7a0357d1-bf3b-54e4-b522-6c15eedf8a93';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-E519BFFF-E7E6-4152-B57B-325564FA7B29';
    $pane->panel = 'os_bottom_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'groups_events_upcoming_events-panel_pane_2';
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
    $pane->uuid = 'E519BFFF-E7E6-4152-B57B-325564FA7B29';
    $display->content['new-E519BFFF-E7E6-4152-B57B-325564FA7B29'] = $pane;
    $display->panels['os_bottom_left'][0] = 'new-E519BFFF-E7E6-4152-B57B-325564FA7B29';
    $pane = new stdClass();
    $pane->pid = 'new-cd740d02-05e4-4170-ac8f-a7c5d32da4aa';
    $pane->panel = 'os_bottom_right';
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
    $pane->uuid = 'cd740d02-05e4-4170-ac8f-a7c5d32da4aa';
    $display->content['new-cd740d02-05e4-4170-ac8f-a7c5d32da4aa'] = $pane;
    $display->panels['os_bottom_right'][0] = 'new-cd740d02-05e4-4170-ac8f-a7c5d32da4aa';
    $pane = new stdClass();
    $pane->pid = 'new-475C678A-C354-4C0F-ACFF-CC28E9A65F89';
    $pane->panel = 'os_middle';
    $pane->type = 'block';
    $pane->subtype = 'groups_homepage-groups_community_banner';
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
    $pane->uuid = '475C678A-C354-4C0F-ACFF-CC28E9A65F89';
    $display->content['new-475C678A-C354-4C0F-ACFF-CC28E9A65F89'] = $pane;
    $display->panels['os_middle'][0] = 'new-475C678A-C354-4C0F-ACFF-CC28E9A65F89';
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
    $pane = new stdClass();
    $pane->pid = 'new-cbab0010-59c4-4d7c-8bf9-bb00f7739528';
    $pane->panel = 'os_top_left';
    $pane->type = 'block';
    $pane->subtype = 'groups_homepage-groups_homepage_welcome';
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
    $pane->uuid = 'cbab0010-59c4-4d7c-8bf9-bb00f7739528';
    $display->content['new-cbab0010-59c4-4d7c-8bf9-bb00f7739528'] = $pane;
    $display->panels['os_top_left'][0] = 'new-cbab0010-59c4-4d7c-8bf9-bb00f7739528';
    $pane = new stdClass();
    $pane->pid = 'new-9549F3B2-A31A-461B-A0FF-F271AB77DC93';
    $pane->panel = 'os_top_right';
    $pane->type = 'block';
    $pane->subtype = 'groups_homepage-groups_community_guides';
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
    $pane->uuid = '9549F3B2-A31A-461B-A0FF-F271AB77DC93';
    $display->content['new-9549F3B2-A31A-461B-A0FF-F271AB77DC93'] = $pane;
    $display->panels['os_top_right'][0] = 'new-9549F3B2-A31A-461B-A0FF-F271AB77DC93';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['groups_home'] = $page;

  return $pages;

}
