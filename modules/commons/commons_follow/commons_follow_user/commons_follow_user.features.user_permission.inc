<?php
/**
 * @file
 * commons_follow_user.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function commons_follow_user_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'flag commons_follow_user'.
  $permissions['flag commons_follow_user'] = array(
    'name' => 'flag commons_follow_user',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag commons_follow_user'.
  $permissions['unflag commons_follow_user'] = array(
    'name' => 'unflag commons_follow_user',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  return $permissions;
}