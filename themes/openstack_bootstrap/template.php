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

/**
 * Implements hook_theme().
 */
function openstack_bootstrap_theme($existing, $type, $theme, $path) {
  return array(
    // Register the newly added theme_form_content() hook so we can utilize
    // theme hook suggestions.
    // @see commons_bootstrap_form_alter().
    'form_content' => array(
      'render element' => 'form',
      'path' => drupal_get_path('theme', 'openstack_bootstrap') . '/templates',
      'template' => 'form-content',
      'pattern' => 'form_content__',
    ),
  );
}

/**
 * Implements hook_form_alter().
 */
function openstack_bootstrap_form_alter(&$form, &$form_state, $form_id) {
  // Give forms a common theme function so we do not have to declare every
  // single form we want to override in hook_theme().
  if (is_array($form['#theme'])) {
    $hooks = array('form_content');
    $form['#theme'] = array_merge($form['#theme'], $hooks);
  }
  else {
    $form['#theme'] = array(
      $form['#theme'],
      'form_content',
    );
  }
}

/**
 * Implements hook_preprocess_form_content().
 */
function openstack_bootstrap_preprocess_form_content(&$variables, $hook) {
  // Bootstrap the with some of Drupal's default variables.
  template_preprocess($variables, $hook);

  if (strpos($variables['form']['#form_id'], 'commons_bw_partial_node_form_') === 0) {
    $variables['form']['actions']['submit']['#attributes']['class'][] = 'action-item-primary';
    if (isset($variables['form']['title'])) {
      $variables['form']['title']['#markup'] = '<h3 class="partial-node-form-title">' . $variables['form']['title']['#markup'] . '</h3>';
    }
  }
}

/**
 * Override or insert variables into the node templates.
 */
function openstack_bootstrap_preprocess_node(&$variables, $hook) {
  $node = $variables['node'];
  $wrapper = entity_metadata_wrapper('node', $node);
  // Use timeago module for formatting node submission date
  // if it is enabled and also configured to be used on nodes.
  if (module_exists('timeago') && variable_get('timeago_node', 1)) {
    $variables['date'] = timeago_format_date($node->created, $variables['date']);
    $use_timeago_date_format = TRUE;
  }
  else {
    $use_timeago_date_format = FALSE;
  }
  // If there does happen to be a user image, add a class for styling purposes.
  if (!empty($variables['user_picture'])) {
    $variables['classes_array'][] = 'user-picture-available';
  }
  // Replace the submitted text on nodes with something a bit more pertinent to
  // the content type.
  if (variable_get('node_submitted_' . $node->type, TRUE)) {
    $node_type_info = node_type_get_type($variables['node']);
    $type_attributes = array('class' => array(
      'node-content-type',
      drupal_html_class('node-content-type-' . $node->type),
    ));
    $placeholders = array(
      '!type' => '<span' . drupal_attributes($type_attributes) . '>' . check_plain($node_type_info->name) . '</span>',
      '!user' => $variables['name'],
      '!date' => $variables['date'],
      '@interval' => format_interval(REQUEST_TIME - $node->created),
    );
    if (!empty($node->{OG_AUDIENCE_FIELD}) && $wrapper->{OG_AUDIENCE_FIELD}->count() == 1) {
      $placeholders['!group'] = l($wrapper->{OG_AUDIENCE_FIELD}->get(0)->label(), 'node/' . $wrapper->{OG_AUDIENCE_FIELD}->get(0)->getIdentifier());
      if ($use_timeago_date_format == TRUE) {
        $variables['submitted'] = t('!type created !date in the !group group by !user', $placeholders);
      }
      else {
        $variables['submitted'] = t('!type created @interval ago in the !group group by !user', $placeholders);
      }
    }
    else {
      if ($use_timeago_date_format == TRUE) {
        $variables['submitted'] = t('!type created !date by !user', $placeholders);
      }
      else {
        $variables['submitted'] = t('!type created @interval ago by !user', $placeholders);
      }
    }
  }
  // Notice: a not-so-nice hack to pass submitted variable to custom node.tpl.php, some module
  // overwrites the original submitted variable, so we are passing submitted_ now.
  // @see templates/node.tpl.php
  $variables['submitted_'] = $variables['submitted'];

  // Remove the group output from nodes
  if (isset($variables['content']['og_group_ref'])) {
    unset($variables['content']['og_group_ref']);
  }
  // Remove the like link
  if (isset($variables['content']['rate_commons_like'])) {
    unset($variables['content']['rate_commons_like']);
  }
  $content_nodes = array('post', 'question', 'poll');
  if (!$variables['teaser'] && in_array($node->type, $content_nodes)) {
    // remove add new comment from non-teaser view modes.
    if (isset($variables['content']['links']['comment'])) {
      unset($variables['content']['links']['comment']);
    }
    if (isset($variables['content']['links']['rate'])) {
      unset($variables['content']['links']['rate']);
    }
    if (isset($variables['content']['links']['flag']['#links']['flag-inappropriate_node'])) {
      unset($variables['content']['links']['flag']['#links']['flag-inappropriate_node']);
    }
  }
  // Remove Log in or register from comments
  openstack_bootstrap_preprocess_comment($variables);
}

/**
 * Implements hook_preprocess_comment()
 */
function openstack_bootstrap_preprocess_comment(&$variables) {
  // Remove Log in or register from comments
  if (isset($variables['content']['links']['comment']['#links']['comment_forbidden'])) {
    unset($variables['content']['links']['comment']['#links']['comment_forbidden']);
  }
}

/**
 * Implements template_preprocess_views_view()
 */
function openstack_bootstrap_preprocess_views_view(&$variables) {
  $view = $variables['view'];
  // Remove exposed filters from Browsing Widget
  if (strpos($view->name, 'commons_bw_') !== false) {
    $variables['exposed'] = '';
  }
}