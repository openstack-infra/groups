<?php

/**
 * Menu callback: displays the groups_oauth2 module settings page.
 *
 * @ingroup forms
 *
 * @see groups_oauth2_admin_settings_validate()
 */
function groups_oauth2_admin_settings($form) {
  $form['groups_oauth2_provider'] = array(
    '#type' => 'textfield',
    '#title' => t('OAuth2 Provider URL'),
    '#default_value' => variable_get('groups_oauth2_provider'),
    '#required' => TRUE,
  );
  $form['groups_oauth2_client_id'] = array(
    '#type' => 'textfield',
    '#title' => t('OAuth2 Client ID'),
    '#default_value' => variable_get('groups_oauth2_client_id'),
    '#required' => TRUE,
  );
  $form['groups_oauth2_client_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('OAuth2 Client Secret'),
    '#default_value' => variable_get('groups_oauth2_client_secret'),
    '#required' => TRUE,
  );
  $form['#validate'][] = 'groups_oauth2_admin_settings_validate';
  return system_settings_form($form);
}

/**
 * Form validation handler for groups_oauth2_admin_settings().
 */
function groups_oauth2_admin_settings_validate($form, &$form_state) {
  if (valid_url($form_state['values']['groups_oauth2_provider'], TRUE) == FALSE) {
    form_set_error('allmyles_wsclient', t('The provider url value must be a valid url.'));
  }
}