<?php
/**
 * @file
 * groups_homepage.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function groups_homepage_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:home
  $menu_links['main-menu:home'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'home',
    'router_path' => 'home',
    'link_title' => 'Groups Home',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -20,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Groups Home');


  return $menu_links;
}
