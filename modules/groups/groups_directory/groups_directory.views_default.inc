<?php
/**
 * @file
 * groups_directory.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function groups_directory_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'groups_groups_directory';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Groups directory';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_group_location_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Group location */
  $handler->display->display_options['fields']['field_group_location_1']['id'] = 'field_group_location_1';
  $handler->display->display_options['fields']['field_group_location_1']['table'] = 'field_data_field_group_location';
  $handler->display->display_options['fields']['field_group_location_1']['field'] = 'field_group_location';
  $handler->display->display_options['fields']['field_group_location_1']['label'] = '';
  $handler->display->display_options['fields']['field_group_location_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_group_location_1']['alter']['text'] = '[field_group_location_1-continent]';
  $handler->display->display_options['fields']['field_group_location_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_group_location_1']['click_sort_column'] = 'continent';
  $handler->display->display_options['fields']['field_group_location_1']['type'] = 'field_group_location_continent';
  /* Sort criterion: Content: Group location (field_group_location:continent) */
  $handler->display->display_options['sorts']['field_group_location_continent']['id'] = 'field_group_location_continent';
  $handler->display->display_options['sorts']['field_group_location_continent']['table'] = 'field_data_field_group_location';
  $handler->display->display_options['sorts']['field_group_location_continent']['field'] = 'field_group_location_continent';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'group' => 'group',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $translatables['groups_groups_directory'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('[field_group_location_1-continent]'),
    t('Content pane'),
    t('View panes'),
  );
  $export['groups_groups_directory'] = $view;

  return $export;
}
