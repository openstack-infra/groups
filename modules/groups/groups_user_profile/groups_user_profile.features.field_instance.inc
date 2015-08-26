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

  // Exported field_instance: 'user-user-field_alternate_user_picture'
  $field_instances['user-user-field_alternate_user_picture'] = array(
    'bundle' => 'user',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'profile_teaser' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => 'content',
          'image_style' => '300x300_avatar',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'display_in_partial_form' => 0,
    'entity_type' => 'user',
    'field_name' => 'field_alternate_user_picture',
    'label' => 'Alternate User Picture',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'user-user-field_ambassador_region'
  $field_instances['user-user-field_ambassador_region'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 11,
      ),
      'profile_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
    ),
    'display_in_partial_form' => 0,
    'entity_type' => 'user',
    'field_name' => 'field_ambassador_region',
    'label' => 'Ambassador region',
    'required' => 0,
    'settings' => array(
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 12,
    ),
  );

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
        'weight' => 4,
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
  t('Alternate User Picture');
  t('Ambassador region');
  t('Weibo URL');

  return $field_instances;
}
