<?php
/**
 * @file
 * groups_groups.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function groups_groups_user_default_roles() {
  $roles = array();

  // Exported role: ambassador.
  $roles['ambassador'] = array(
    'name' => 'ambassador',
    'weight' => 11,
  );

  // Exported role: community_manager.
  $roles['community_manager'] = array(
    'name' => 'community_manager',
    'weight' => 12,
  );

  return $roles;
}
