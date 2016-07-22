<?php

/**
 * Menu callback: displays the groups_reports module settings page.
 *
 * @ingroup forms
 */
function groups_reports_admin_settings($form) {
  $form['groups_contact_report_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Organizer contact report token'),
    '#default_value' => variable_get('groups_contact_report_key', 'dummytoken'),
    '#required' => TRUE,
  );
  return system_settings_form($form);
}