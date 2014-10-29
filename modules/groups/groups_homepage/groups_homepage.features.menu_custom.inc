<?php
/**
 * @file
 * groups_homepage.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function groups_homepage_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-content-menu.
  $menus['menu-content-menu'] = array(
    'menu_name' => 'menu-content-menu',
    'title' => 'Content Menu',
    'description' => 'The content menu contains links for static pages.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Content Menu');
  t('Main menu');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');
  t('The content menu contains links for static pages.');


  return $menus;
}
