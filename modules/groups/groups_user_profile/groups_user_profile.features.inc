<?php
/**
 * @file
 * groups_user_profile.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function groups_user_profile_image_default_styles() {
  $styles = array();

  // Exported image style: 300x300_avatar.
  $styles['300x300_avatar'] = array(
    'label' => '300x300 Profile',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
