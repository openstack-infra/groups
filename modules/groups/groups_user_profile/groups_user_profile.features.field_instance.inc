<?php
/**
 * @file
 * groups_user_profile.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function groups_user_profile_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-user-field_weibo_url'
  $field_instances['user-user-field_weibo_url'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 10,
      ),
      'profile_teaser' => array(
        'label' => 'hidden',
        'module' => 'groups_social_link',
        'settings' => array(
          'provider' => 'weibo',
        ),
        'type' => 'groups_social_link_formatter',
        'weight' => 3,
      ),
    ),
    'display_in_partial_form' => 0,
    'entity_type' => 'user',
    'field_name' => 'field_weibo_url',
    'label' => 'Weibo URL',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => 'weibo-url',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => 0,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 7,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Weibo URL');

  return $field_instances;
}
