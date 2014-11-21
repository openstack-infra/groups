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


/**
 * Implements hook_page_alter().
 *
 * Relocate utility links from header to utility region.
 */
function openstack_bootstrap_page_alter(&$page) {
  if (isset($page['header']['commons_utility_links_commons_utility_links'])) {
    $page['utility']['commons_utility_links_commons_utility_links'] =
      $page['header']['commons_utility_links_commons_utility_links'];
    unset($page['header']['commons_utility_links_commons_utility_links']);
  }
}

/**
 * Render a Sign in button to anonymous users and a dropdown-menu of
 * utility links for authenticated ones.
 */
function openstack_bootstrap_links__commons_utility_links(&$variables) {
  if (user_is_logged_in()) {
    global $user;
    $variables['attributes']['class'][] = 'dropdown-menu';
    $variables['attributes']['class'][] = 'dropdown-menu-right';
    $output = '<div class="btn-group">';
    $output .= '<button class="btn dropdown-toggle" type="button" data-toggle="dropdown"><span class="glyphicon glyphicon-user"></span>
    '.format_username($user).'<span class="caret"></span>
  </button>';
    $output .= theme_links($variables);
    $output .= '</div>';
    return $output;
  } else {
    // render the signup button only
    $link = $variables['links']['signup'];
    $link['attributes']['class'][] = 'btn-sign-in';
    return l($link['title'], $link['href'], $link);
  }
}