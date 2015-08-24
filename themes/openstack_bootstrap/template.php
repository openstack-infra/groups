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
  drupal_add_css('//netdna.bootstrapcdn.com/font-awesome/4.4.0/css/font-awesome.css', array('type' => 'external'));
}

/**
 * Implements hook_preprocess_html().
 *
 * Add bleed-margins class to
 *  - front page
 *  - ambassador program
 *
 * and add no-bleed-margins to each other page.
 *
 * @see html.tpl.php
 */
function openstack_bootstrap_preprocess_html(&$variables) {
  $path_alias = drupal_get_path_alias();
  if (($variables['is_front']) || ($path_alias == 'ambassador-program')) {
    $variables['classes_array'][] = 'bleed-margins';
  } else {
    $variables['classes_array'][] = 'no-bleed-margins';
  }
}

/**
 * Implements hook_preprocess_field().
 */
function openstack_bootstrap_preprocess_field(&$variables, $hook) {
  if ($node = menu_get_object()) {
    if (($node->type == 'group') && ($variables['field_name_css'] == 'field-group-status')) {
      $status = $node->field_group_status[LANGUAGE_NONE][0]['value'] == 1;
      $variables['items'][0]['#markup'] = $status ? '<div class="group-status-logo"></div>'.t('Official user group') : '';
    }
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
  // Add group-status-[official|unsupported] class to css
  if ($node->type == 'group') {
    $status = $node->field_group_status[LANGUAGE_NONE][0]['value'] == 1;
    $variables['classes_array'][] = $status ? 'group-status-official' : 'group-status-unsupported';
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

/**
 * Implements template_preprocess_user_profile()
 */
function openstack_bootstrap_preprocess_user_profile(&$variables) {
  global $user;
  $account = $variables['elements']['#account'];
  if ($variables['elements']['#view_mode'] == 'profile_teaser') {
    $node_wrapper = entity_metadata_wrapper('user', $account);
    $region_value = $node_wrapper->field_ambassador_region->value();
    if (isset($region_value)) {
      // echo "<pre>";
      // print_r($account->name);
      // die('-y-');
      module_load_include('inc', 'field_group_location', 'field_group_lookup');
      $continents = _continent_get_predefined_list();
      $variables['user_profile']['name'][0] = array(
        '#markup' => '<h3><a href="">'.$account->name.
          ' <span class="ambassador-region">// '.$continents[$region_value].'</span></a></h3>',
      );
    }
  }
  if (in_array('ambassador', $account->roles)) {
    $variables['user_profile']['role_ambassador'] = array(
      '#prefix' => '<span class="label label-info">',
      '#markup' => t('Ambassador'),
      '#suffix' => '</span>',
    );
  }
  if (in_array('community_manager', $account->roles)) {
    $variables['user_profile']['role_community_manager'] = array(
      '#prefix' => '<span class="label label-info">',
      '#markup' => t('Community Manager'),
      '#suffix' => '</span>',
    );
  }
  if (((in_array('community_manager', $user->roles)) ||
       (in_array('ambassador', $user->roles)) ||
       (in_array('administrator', $user->roles))) && ($user->uid == $account->uid)) {
    $pending_groups = db_select('node', 'n')
      ->fields('n')
      ->condition('n.status', 0, '=')
      ->countQuery()
      ->execute()
      ->fetchField();
    if ($pending_groups > 0) {
      $content = l(t('@pending group(s) waiting in the review queue', array('@pending' => $pending_groups)),
          'admin/content/groups');
    } else {
      $content = t('No new groups waiting in the review queue.');
    }
    $variables['user_profile']['pending_groups'] = array(
      '#prefix' => '<h3>'.t('Groups waiting for approval').'</h3>',
      '#markup' => $content,
    );
    $variables['user_profile']['reports'] = array(
      '#prefix' => '<h3>'.t('Reports').'</h3>',
      '#markup' =>
        '<div>'.l('User group membership report', 'reports/groups-membership-report').'</div>'.
        '<div>'.l('Membership history report', 'reports/groups-membership-history-report').'</div>'.
        '<div>'.l('Group status report', 'reports/group-status-report').'</div>',
    );
  }
  if (user_is_logged_in()) {
    $variables['user_profile']['register_new_group'] = array(
      '#prefix' => '<h3>'.t('Groups registration').'</h3>',
      '#markup' => l('Register a new user group', 'node/add/group'),
    );
  }
}