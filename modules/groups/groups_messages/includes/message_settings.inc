<?php

/**
 * Build message settings form
 */
function groups_messages_message_settings_form($form, &$form_state, $account) {
  $form['uid'] = array(
    '#type' => 'value',
    '#value' => $account->uid,
  );
  $form['privatemsg']['pm_send_notifications'] = array(
    '#type' => 'checkbox',
    '#title' => t('Receive email notification for incoming private messages'),
    '#default_value' => _pm_email_notify_is_enabled($account->uid),
    '#states' => array(
      'visible' => array(
        ':input[name="pm_enable"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save message settings'),
  );

  return $form;
}

/**
 * Implements hook_form_submit()
 */
function groups_messages_message_settings_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  db_merge('pm_email_notify')
    ->fields(array('email_notify_is_enabled' => $values['pm_send_notifications']))
    ->key(array('user_id' => $values['uid']))
    ->execute();
}