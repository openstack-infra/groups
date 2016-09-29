<?php
/**
 * @file
 * commons_content_moderation.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function commons_content_moderation_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'flag abuse_user'.
  $permissions['flag abuse_user'] = array(
    'name' => 'flag abuse_user',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag inappropriate_comment'.
  $permissions['flag inappropriate_comment'] = array(
    'name' => 'flag inappropriate_comment',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag inappropriate_node'.
  $permissions['flag inappropriate_node'] = array(
    'name' => 'flag inappropriate_node',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag abuse_user'.
  $permissions['unflag abuse_user'] = array(
    'name' => 'unflag abuse_user',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag inappropriate_comment'.
  $permissions['unflag inappropriate_comment'] = array(
    'name' => 'unflag inappropriate_comment',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag inappropriate_node'.
  $permissions['unflag inappropriate_node'] = array(
    'name' => 'unflag inappropriate_node',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  return $permissions;
}