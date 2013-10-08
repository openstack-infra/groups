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

  // Exported field_base: 'field_geofield'
  $field_bases['field_geofield'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_geofield',
    'foreign keys' => array(),
    'indexes' => array(
      'bbox' => array(
        0 => 'top',
        1 => 'bottom',
        2 => 'left',
        3 => 'right',
      ),
      'bottom' => array(
        0 => 'bottom',
      ),
      'centroid' => array(
        0 => 'lat',
        1 => 'lon',
      ),
      'geohash' => array(
        0 => 'geohash',
      ),
      'lat' => array(
        0 => 'lat',
      ),
      'left' => array(
        0 => 'left',
      ),
      'lon' => array(
        0 => 'lon',
      ),
      'right' => array(
        0 => 'right',
      ),
      'top' => array(
        0 => 'top',
      ),
    ),
    'locked' => 0,
    'module' => 'geofield',
    'settings' => array(
      'backend' => 'default',
      'srid' => 4326,
    ),
    'translatable' => 0,
    'type' => 'geofield',
  );

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
