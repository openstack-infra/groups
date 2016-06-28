<?php

/**
 * Remove duplicate entries from a full user name
 *
 * @param $fullname
 *  The full user name.
 * @return
 *  The user name without duplicate entries.
 *  For example: Michael Scott Scott will be Michael Scott
 */
function _groups_oauth2_remove_fullname_duplicates($fullname) {
  $parts = explode(' ', $fullname);
  if (count($parts) > 2) {
    $build_str = '';
    $last_element = '';
    foreach ($parts as $key => $value) {
      $value = trim($value);
      if (($value != $last_element) && ($value != '')) {
        $build_str .= $key > 0 ? ' '.$value : $value;
      }
      $last_element = $value;
    }
  } else {
    $build_str = $fullname;
  }
  return $build_str;
}

/**
 * Construct a normalized user name from full name.
 *
 * @param $fullname
 *   The full name of the user account
 * @return
 *   Normalized user name.
 */
function _groups_oauth2_get_username_from_fullname($fullname) {
  $username = check_plain(strtolower($fullname));
  $query = "SELECT uid FROM {users} WHERE name = :name";
  $uid = db_query($query, array(':name' => $username))->fetchField();
  $i = 0;
  while ($uid) {
    $i++;
    $uid = db_query($query, array(':name' => ($username . $i)))->fetchField();
  }
  if ($i > 0) {
    $username = $username . $i;
  }
  return $username;
}

/**
 * Normalize the user name properties of an user entity.
 *
 * Rewrite both data->oauth2_fullname and username fields and remove
 * duplicated name entries.
 *
 * @param $user
 *  The user entity.
 * @return
 *  Return NULL if the full name was properly defined, otherwise
 *  the normalized full name.
 */
function _groups_oauth2_normalize_user_name($user) {
  $result = '';
  if (isset($user->data['oauth2_fullname'])) {
    $fullname = $user->data['oauth2_fullname'];
    $normalized_fullname = _groups_oauth2_remove_fullname_duplicates($fullname);
    if ($fullname != $normalized_fullname) {
      $edit = array('data' => $user->data);
      $edit['name'] = _groups_oauth2_get_username_from_fullname($normalized_fullname);
      $edit['data']['oauth2_fullname'] = $normalized_fullname;
      user_save($user, $edit);
      $result = $normalized_fullname;
    }
  }
  return $result;
}
