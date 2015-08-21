<?php
/**
 * @file
 * groups_ambassador.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function groups_ambassador_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function groups_ambassador_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
