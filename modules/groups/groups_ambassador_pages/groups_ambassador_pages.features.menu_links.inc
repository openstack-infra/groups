<?php
/**
 * @file
 * groups_ambassador_pages.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function groups_ambassador_pages_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_ambassador-program:ambassador-program
  $menu_links['main-menu_ambassador-program:ambassador-program'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'ambassador-program',
    'router_path' => 'ambassador-program',
    'link_title' => 'Ambassador Program',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'main-menu_ambassador-program:ambassador-program',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 20,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Ambassador Program');


  return $menu_links;
}
