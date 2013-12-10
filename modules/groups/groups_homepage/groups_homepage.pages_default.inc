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
    ),
  );
  $display->cache = array();
  $display->title = 'Groups Home';
  $display->uuid = '7a0357d1-bf3b-54e4-b522-6c15eedf8a93';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4149ec78-f9ea-2084-5961-19adcd9726c5';
    $pane->panel = 'os_bottom_left';
    $pane->type = 'block';
    $pane->subtype = 'groups_homepage-groups_community_map';
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
    $pane->uuid = '4149ec78-f9ea-2084-5961-19adcd9726c5';
    $display->content['new-4149ec78-f9ea-2084-5961-19adcd9726c5'] = $pane;
    $display->panels['os_bottom_left'][0] = 'new-4149ec78-f9ea-2084-5961-19adcd9726c5';
    $pane = new stdClass();
    $pane->pid = 'new-c2b9e460-b848-d8f4-8153-cf0687afd8ea';
    $pane->panel = 'os_bottom_right';
    $pane->type = 'block';
    $pane->subtype = 'groups_homepage-groups_find_nearby';
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
    $pane->uuid = 'c2b9e460-b848-d8f4-8153-cf0687afd8ea';
    $display->content['new-c2b9e460-b848-d8f4-8153-cf0687afd8ea'] = $pane;
    $display->panels['os_bottom_right'][0] = 'new-c2b9e460-b848-d8f4-8153-cf0687afd8ea';
    $pane = new stdClass();
    $pane->pid = 'new-1a23fada-1c8b-2cf4-2978-e8aa64e28877';
    $pane->panel = 'os_center';
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
    $display->panels['os_center'][0] = 'new-1a23fada-1c8b-2cf4-2978-e8aa64e28877';
    $pane = new stdClass();
    $pane->pid = 'new-dd6ca3f4-3444-af04-f1e2-47c9f488ed53';
    $pane->panel = 'os_left';
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
    $pane->uuid = 'dd6ca3f4-3444-af04-f1e2-47c9f488ed53';
    $display->content['new-dd6ca3f4-3444-af04-f1e2-47c9f488ed53'] = $pane;
    $display->panels['os_left'][0] = 'new-dd6ca3f4-3444-af04-f1e2-47c9f488ed53';
    $pane = new stdClass();
    $pane->pid = 'new-7ae087d4-887e-4b54-b980-44fb87245089';
    $pane->panel = 'os_middle';
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
    $display->panels['os_middle'][0] = 'new-7ae087d4-887e-4b54-b980-44fb87245089';
    $pane = new stdClass();
    $pane->pid = 'new-4f60b089-fac8-aa14-d1f8-d5674b0d51bc';
    $pane->panel = 'os_right';
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
    $pane->uuid = '4f60b089-fac8-aa14-d1f8-d5674b0d51bc';
    $display->content['new-4f60b089-fac8-aa14-d1f8-d5674b0d51bc'] = $pane;
    $display->panels['os_right'][0] = 'new-4f60b089-fac8-aa14-d1f8-d5674b0d51bc';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['groups_home'] = $page;

  return $pages;

}
