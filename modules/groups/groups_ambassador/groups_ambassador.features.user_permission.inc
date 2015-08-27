<?php
/**
 * @file
 * groups_ambassador.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function groups_ambassador_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create ambassador_application content'.
  $permissions['create ambassador_application content'] = array(
    'name' => 'create ambassador_application content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any ambassador_application content'.
  $permissions['delete any ambassador_application content'] = array(
    'name' => 'delete any ambassador_application content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own ambassador_application content'.
  $permissions['delete own ambassador_application content'] = array(
    'name' => 'delete own ambassador_application content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any ambassador_application content'.
  $permissions['edit any ambassador_application content'] = array(
    'name' => 'edit any ambassador_application content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own ambassador_application content'.
  $permissions['edit own ambassador_application content'] = array(
    'name' => 'edit own ambassador_application content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
