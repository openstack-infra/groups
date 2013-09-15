<?php
/**
 * @file
 * groups_groups.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function groups_groups_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-group-field_resource_links'
  $field_instances['node-group-field_resource_links'] = array(
    'bundle' => 'group',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_property_list',
        'settings' => array(),
        'type' => 'field_property_list_raw',
        'weight' => 15,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_resource_links',
    'label' => 'Resource links',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_property_list',
      'settings' => array(),
      'type' => 'field_property_list',
      'weight' => 45,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Resource links');

  return $field_instances;
}
