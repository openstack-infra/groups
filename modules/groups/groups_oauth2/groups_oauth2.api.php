<?php
/**
 * @file
 * This file contains API documentation for the Groups OAuth2 module. Note that
 * all of this code is merely for example purposes, it is never executed when
 * using the Groups OAuth2 module.
 */

/**
 * Hook to map account data to a Drupal user after connecting.
 *
 * This hook is fired after a user account is created by groups
 * oauth2 module.
 *
 * @param  $account
 *   A user account array.
 * @param  $userinfo
 *   A user profile returned by oauth2 provider.
 * @return
 *   None.
 */
function hook_oauth2_user_save(&$account, $userinfo) {

}