<?php
/**
 * @file
 * groups_user_profile.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function groups_user_profile_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_ambassador_region'
  $field_bases['field_ambassador_region'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_ambassador_region',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'AF' => 'Africa',
        'AS' => 'Asia/Pacific',
        'EU' => 'Europe',
        'NA' => 'North America',
        'SA' => 'South America',
        'OC' => 'Oceania',
        'AN' => 'Antarctica',
        'ME' => 'Middle East',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_weibo_url'
  $field_bases['field_weibo_url'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_weibo_url',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  return $field_bases;
}
