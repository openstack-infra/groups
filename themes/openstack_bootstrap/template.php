<?php

/**
 * @file
 * template.php
 */

/**
 * Implements hook_preprocess_page().
 *
 * @see page.tpl.php
 */
function openstack_bootstrap_preprocess_page(&$variables) {

  if ($variables['navbar_classes_array']) {
    // remove .container from navbar
    $key = array_search('container', $variables['navbar_classes_array']);
    unset($variables['navbar_classes_array'][$key]);
    // replace .navbar-default with .navbar-os and customise the
    // navbar rules.
    $key = array_search('navbar-default', $variables['navbar_classes_array']);
    unset($variables['navbar_classes_array'][$key]);
    $variables['navbar_classes_array'][] = 'navbar-os';
  }
}