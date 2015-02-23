<?php
/**
 * @file
 * groups_groups.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function groups_groups_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'ambassador' => 'ambassador',
      'community_manager' => 'community_manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any group content'.
  $permissions['edit any group content'] = array(
    'name' => 'edit any group content',
    'roles' => array(
      'ambassador' => 'ambassador',
      'community_manager' => 'community_manager',
    ),
    'module' => 'node',
  );

  return $permissions;
}
