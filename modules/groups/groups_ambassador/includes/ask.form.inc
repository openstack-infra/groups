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
  $options = array_merge(array('--' => '-- Select a region --'), _continent_get_predefined_list());
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
 * Implements hook_form_submit()
 */
function groups_ambassador_ask_form_submit($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
  $current_user = user_uid_optional_load();
  // TODO: send message to ambassadors
  $ambassadors = _groups_ambassador_get_ambassador_list();
}