<?php
/**
 * @file
 * groups_groups.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function groups_groups_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_group_location'
  $field_bases['field_group_location'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_group_location',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'field_group_location',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'field_group_location',
  );

  // Exported field_base: 'field_resource_links'
  $field_bases['field_resource_links'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_resource_links',
    'foreign keys' => array(),
    'indexes' => array(
      'key' => array(
        0 => 'key',
      ),
    ),
    'locked' => 0,
    'module' => 'field_property_list',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'field_property_list',
  );

  return $field_bases;
}
