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

  // Exported field_instance: 'node-group-field_geofield'
  $field_instances['node-group-field_geofield'] = array(
    'bundle' => 'group',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'geofield',
        'settings' => array(
          'data' => 'full',
        ),
        'type' => 'geofield_wkt',
        'weight' => 17,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_geofield',
    'label' => 'geofield',
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'geofield',
      'type' => 'geofield_latlon',
      'weight' => 47,
    ),
  );

  // Exported field_instance: 'node-group-field_group_location'
  $field_instances['node-group-field_group_location'] = array(
    'bundle' => 'group',
    'default_value' => array(
      0 => array(
        'country' => 'US',
        'location' => '',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_group_location',
        'settings' => array(),
        'type' => 'field_group_location_simple',
        'weight' => 16,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_group_location',
    'label' => 'Group location',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_group_location',
      'settings' => array(),
      'type' => 'field_group_location',
      'weight' => 46,
    ),
  );

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
  t('Group location');
  t('Resource links');
  t('geofield');

  return $field_instances;
}
