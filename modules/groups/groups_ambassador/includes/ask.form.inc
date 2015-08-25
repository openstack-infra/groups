<?php

/**
 * Form constructor for the Ask the Ambassadors form.
 */
function groups_ambassador_ask_form($form = array(), &$form_state) {
  if (!empty($form_state['values']['region'])) {
    $form['submission'] = array(
      '#markup' => theme('groups_ambassador_submission', array()),
    );
  } else {
    $form = _groups_ambassador_ask_form_build($form, $form_state);
  }
  return $form;
}

/**
 * Ask the Ambassadors form elements.
 */
function _groups_ambassador_ask_form_build($form, &$form_state) {
  module_load_include('inc', 'field_group_location', 'field_group_lookup');
  // enlist available regions only
  $filtered_regions = array();
  $regions = _continent_get_predefined_list();
  $ambassadors = _groups_ambassador_get_ambassador_list();
  foreach ($ambassadors as $ambassador) {
    $region = $ambassador->field_ambassador_region[LANGUAGE_NONE][0]['value'];
    $filtered_regions[$region] = $regions[$region];
  }

  $options = array_merge(array('--' => '-- Select a region --'), $filtered_regions);
  $form['region'] = array(
    '#type' => 'select',
    '#title' => t('Your region'),
    '#options' => $options,
  );
  $form['message'] = array(
    '#type' => 'textarea',
    '#title' => t('Question'),
    '#resizable' => FALSE,
    '#rows' => 10,
    '#required' => TRUE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}

/**
 * Implements hook_validate callback for Ask the Ambassadors form.
 */
function groups_ambassador_ask_form_validate($form, &$form_state) {
  $values = $form_state['values'];
  if ($values['region'] == '--') {
    form_set_error('email', t('Please select a valid region.'));
  }
}

/**
 * Convert standard user array into _privatemsg recipient format.
 */
function groups_ambassador_get_privatemsg_recipients($recipient_users) {
  $recipients = array();
  foreach ($recipient_users as $user) {
    $user->type = 'user';
    $user->recipient = $user->uid;
    $recipients['user_'.$user->uid] = $user;
  }
  return $recipients;
}

/**
 * Implements hook_form_submit()
 */
function groups_ambassador_ask_form_submit($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
  $current_user = user_uid_optional_load();

  // filter ambassadors by region
  $recipient_users = array();
  $ambassadors = _groups_ambassador_get_ambassador_list();
  foreach ($ambassadors as $ambassador) {
    $region = $ambassador->field_ambassador_region[LANGUAGE_NONE][0]['value'];
    if ($region == $form_state['values']['region']) {
      $recipient_users[] = $ambassador;
    }
  }
  $recipients = groups_ambassador_get_privatemsg_recipients($recipient_users);
  $message = (object)array(
    'author' => $current_user,
    'format' => 'filtered_html',
    'timestamp' => time(),
    'recipients' => $recipients,
    'has_tokens' => false,
  );

  $message->subject = t('[Ambassador] Question from @username',
    array('@username' => $current_user->name));

  $message->body = t('You got a question from a groups portal user through '.
    'the ask the ambassador page.<br/><br/>@content',
    array('@content' => $form_state['values']['message']));
  $message = _privatemsg_send($message);
}