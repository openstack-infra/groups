<?php
/**
 * @file
 * groups_ambassador_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function groups_ambassador_pages_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'ambassador_program_page';
  $page->task = 'page';
  $page->admin_title = 'Ambassador Program Page';
  $page->admin_description = '';
  $page->path = 'ambassador-program';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => '',
    'weight' => '0',
    'name' => 'navigation',
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
  $handler->name = 'page_ambassador_program_page__panel_context_af92c1c7-c287-4b5b-9364-242c0abe81a3';
  $handler->task = 'page';
  $handler->subtask = 'ambassador_program_page';
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
      'middle' => NULL,
      'os_top' => NULL,
      'os_top_left' => NULL,
      'os_top_right' => NULL,
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
  $display->title = 'Ambassador Program';
  $display->uuid = '6ddb52e2-863d-4d7f-a7b5-5976ca341ccd';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-773e55a9-0642-480c-8f46-cad7edc9e6c7';
    $pane->panel = 'os_bottom';
    $pane->type = 'block';
    $pane->subtype = 'groups_ambassador-groups_ambassador_ask';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '773e55a9-0642-480c-8f46-cad7edc9e6c7';
    $display->content['new-773e55a9-0642-480c-8f46-cad7edc9e6c7'] = $pane;
    $display->panels['os_bottom'][0] = 'new-773e55a9-0642-480c-8f46-cad7edc9e6c7';
    $pane = new stdClass();
    $pane->pid = 'new-43902f5c-ea84-413e-9c25-8e025ad673f0';
    $pane->panel = 'os_bottom';
    $pane->type = 'block';
    $pane->subtype = 'groups_ambassador-groups_ambassador_faq';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '43902f5c-ea84-413e-9c25-8e025ad673f0';
    $display->content['new-43902f5c-ea84-413e-9c25-8e025ad673f0'] = $pane;
    $display->panels['os_bottom'][1] = 'new-43902f5c-ea84-413e-9c25-8e025ad673f0';
    $pane = new stdClass();
    $pane->pid = 'new-b014ccc9-fa9c-488b-9a83-6238f145fc53';
    $pane->panel = 'os_top';
    $pane->type = 'block';
    $pane->subtype = 'groups_ambassador-groups_ambassador_page_banner';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b014ccc9-fa9c-488b-9a83-6238f145fc53';
    $display->content['new-b014ccc9-fa9c-488b-9a83-6238f145fc53'] = $pane;
    $display->panels['os_top'][0] = 'new-b014ccc9-fa9c-488b-9a83-6238f145fc53';
    $pane = new stdClass();
    $pane->pid = 'new-4c8a52b1-d3ec-45ee-8950-efd18888858f';
    $pane->panel = 'os_top';
    $pane->type = 'views';
    $pane->subtype = 'groups_ambassador_list';
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
      'override_title' => 1,
      'override_title_text' => 'Ambassadors',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '4c8a52b1-d3ec-45ee-8950-efd18888858f';
    $display->content['new-4c8a52b1-d3ec-45ee-8950-efd18888858f'] = $pane;
    $display->panels['os_top'][1] = 'new-4c8a52b1-d3ec-45ee-8950-efd18888858f';
    $pane = new stdClass();
    $pane->pid = 'new-16f9cb5c-04fe-4619-a853-8edaa6a3af42';
    $pane->panel = 'os_top_left';
    $pane->type = 'block';
    $pane->subtype = 'groups_ambassador-groups_ambassador_roleof';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '16f9cb5c-04fe-4619-a853-8edaa6a3af42';
    $display->content['new-16f9cb5c-04fe-4619-a853-8edaa6a3af42'] = $pane;
    $display->panels['os_top_left'][0] = 'new-16f9cb5c-04fe-4619-a853-8edaa6a3af42';
    $pane = new stdClass();
    $pane->pid = 'new-429e267d-dffb-46aa-bfe4-26892f2b3943';
    $pane->panel = 'os_top_right';
    $pane->type = 'block';
    $pane->subtype = 'groups_ambassador-groups_ambassador_selection';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '429e267d-dffb-46aa-bfe4-26892f2b3943';
    $display->content['new-429e267d-dffb-46aa-bfe4-26892f2b3943'] = $pane;
    $display->panels['os_top_right'][0] = 'new-429e267d-dffb-46aa-bfe4-26892f2b3943';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['ambassador_program_page'] = $page;

  return $pages;

}
