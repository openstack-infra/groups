<?php
/**
 * @file
 * groups_pages.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function groups_pages_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:group:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'group';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
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
  $display->title = '%node:title';
  $display->uuid = 'E6B07C18-BB1E-460D-BFDA-18B5E5E701AD';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-D535E2E0-1D0E-4B62-9093-D9DE4722EB29';
    $pane->panel = 'two_66_33_first';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
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
    $pane->uuid = 'D535E2E0-1D0E-4B62-9093-D9DE4722EB29';
    $display->content['new-D535E2E0-1D0E-4B62-9093-D9DE4722EB29'] = $pane;
    $display->panels['two_66_33_first'][0] = 'new-D535E2E0-1D0E-4B62-9093-D9DE4722EB29';
    $pane = new stdClass();
    $pane->pid = 'new-54C2DF39-C222-48D2-A1E6-31E4C9D18B4F';
    $pane->panel = 'two_66_33_first';
    $pane->type = 'views_panes';
    $pane->subtype = 'groups_events_upcoming_events-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'panelizer',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '54C2DF39-C222-48D2-A1E6-31E4C9D18B4F';
    $display->content['new-54C2DF39-C222-48D2-A1E6-31E4C9D18B4F'] = $pane;
    $display->panels['two_66_33_first'][1] = 'new-54C2DF39-C222-48D2-A1E6-31E4C9D18B4F';
    $pane = new stdClass();
    $pane->pid = 'new-4D07DA83-5650-4EE6-AA34-DEBDE8467ADB';
    $pane->panel = 'two_66_33_first';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_resource_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'field_property_list_raw',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '4D07DA83-5650-4EE6-AA34-DEBDE8467ADB';
    $display->content['new-4D07DA83-5650-4EE6-AA34-DEBDE8467ADB'] = $pane;
    $display->panels['two_66_33_first'][2] = 'new-4D07DA83-5650-4EE6-AA34-DEBDE8467ADB';
    $pane = new stdClass();
    $pane->pid = 'new-0E5D035F-F2A0-4A1A-A237-3360F3284ED9';
    $pane->panel = 'two_66_33_first';
    $pane->type = 'commons_bw_group';
    $pane->subtype = 'commons_bw_group';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '0E5D035F-F2A0-4A1A-A237-3360F3284ED9';
    $display->content['new-0E5D035F-F2A0-4A1A-A237-3360F3284ED9'] = $pane;
    $display->panels['two_66_33_first'][3] = 'new-0E5D035F-F2A0-4A1A-A237-3360F3284ED9';
    $pane = new stdClass();
    $pane->pid = 'new-0702E7C9-CCB9-4EA3-B2C5-7D1ACDF55BD5';
    $pane->panel = 'two_66_33_second';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:group_group';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'og_group_subscribe',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'field_name' => '0',
      ),
      'context' => 'panelizer',
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
    $pane->uuid = '0702E7C9-CCB9-4EA3-B2C5-7D1ACDF55BD5';
    $display->content['new-0702E7C9-CCB9-4EA3-B2C5-7D1ACDF55BD5'] = $pane;
    $display->panels['two_66_33_second'][0] = 'new-0702E7C9-CCB9-4EA3-B2C5-7D1ACDF55BD5';
    $pane = new stdClass();
    $pane->pid = 'new-89D9A851-8F3A-45BA-AF74-7E55EBF9BB3C';
    $pane->panel = 'two_66_33_second';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_group_status';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'list_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
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
    $pane->uuid = '89D9A851-8F3A-45BA-AF74-7E55EBF9BB3C';
    $display->content['new-89D9A851-8F3A-45BA-AF74-7E55EBF9BB3C'] = $pane;
    $display->panels['two_66_33_second'][1] = 'new-89D9A851-8F3A-45BA-AF74-7E55EBF9BB3C';
    $pane = new stdClass();
    $pane->pid = 'new-95912BBD-5323-4916-B618-6308E1262D31';
    $pane->panel = 'two_66_33_second';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_ambassadors';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'og_list_default',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'link' => 0,
        'view_mode' => 'default',
        'links' => 1,
      ),
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => 'Ambassadors of this group',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '95912BBD-5323-4916-B618-6308E1262D31';
    $display->content['new-95912BBD-5323-4916-B618-6308E1262D31'] = $pane;
    $display->panels['two_66_33_second'][2] = 'new-95912BBD-5323-4916-B618-6308E1262D31';
    $pane = new stdClass();
    $pane->pid = 'new-B17247AB-8C6E-4DB5-A8E0-78C8CF4462FA';
    $pane->panel = 'two_66_33_second';
    $pane->type = 'views_panes';
    $pane->subtype = 'activity_group-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'items_per_page' => '5',
      'arguments' => array(
        'gid' => '%node:nid',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'B17247AB-8C6E-4DB5-A8E0-78C8CF4462FA';
    $display->content['new-B17247AB-8C6E-4DB5-A8E0-78C8CF4462FA'] = $pane;
    $display->panels['two_66_33_second'][3] = 'new-B17247AB-8C6E-4DB5-A8E0-78C8CF4462FA';
    $pane = new stdClass();
    $pane->pid = 'new-737D0A90-738F-4637-ABE7-39AF64CC3A1F';
    $pane->panel = 'two_66_33_second';
    $pane->type = 'views_panes';
    $pane->subtype = 'commons_contributors_group-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'panelizer',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '737D0A90-738F-4637-ABE7-39AF64CC3A1F';
    $display->content['new-737D0A90-738F-4637-ABE7-39AF64CC3A1F'] = $pane;
    $display->panels['two_66_33_second'][4] = 'new-737D0A90-738F-4637-ABE7-39AF64CC3A1F';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:group:default'] = $panelizer;

  return $export;
}
