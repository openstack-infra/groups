<?php

/**
 * Form constructor for the Ambassador Application form
 */
function groups_ambassador_apply_form($form = array(), &$form_state) {
  if (!empty($form_state['values']['region'])) {
    $form['submission'] = array(
      '#markup' => theme('groups_ambassador_apply_confirm', array()),
    );
  } else {
    $form = _groups_ambassador_apply_form_build($form, $form_state);
  }
  return $form;
}

/**
 * Build Ambassador Application form elements
 */
function _groups_ambassador_apply_form_build($form, &$form_state) {
  $form['region'] = array(
    '#type' => 'textfield',
    '#title' => t('Where do you reside'),
    '#description' => t('Please enter one location as best you can. A helpful '.
      'way to think is where you will spend >6 months out of the next year'),
    '#required' => TRUE,
  );
  $form['reason'] = array(
    '#type' => 'textarea',
    '#title' => t('Why are you applying to become an OpenStack Ambassador?'),
    '#description' => t('Tell us about your passion and your vision!'),
    '#required' => TRUE,
    '#resizable' => FALSE,
    '#rows' => 10,
  );
  $form['participation'] = array(
    '#type' => 'textarea',
    '#title' => t('How have you participated in the OpenStack Community to '.
      'date?'),
    '#description' => t('Are you an ATC? Are you running User Groups? '.
      'Have you setup OpenStack Mini-confs? What\'s your track record...'),
    '#required' => TRUE,
    '#resizable' => FALSE,
    '#rows' => 10,
  );
  $form['ideas'] = array(
    '#type' => 'textarea',
    '#title' => t('What ideas do you have for your community, that you wish '.
      'you had time or resources to implement?'),
    '#description' => t('We\'re practical people - do you have any concrete, '.
      'implementable ideas derived from that passion or vision above?'),
    '#required' => TRUE,
    '#resizable' => FALSE,
    '#rows' => 10,
  );
  $form['collaboration'] = array(
    '#type' => 'textarea',
    '#title' => t('How will you work with others to achieve your goals?'),
    '#description' => t('A great leader doesn\'t work alone, and we\'re keen '.
      'for you to demonstrate how you intend to work with others both in your '.
      'local area and abroad.'),
    '#required' => TRUE,
    '#resizable' => FALSE,
    '#rows' => 10,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}

/**
 * Implements hook_form_submit()
 */
function groups_ambassador_apply_form_submit($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
  $node = _groups_ambassador_create_application_node($form_state['values']);
  _groups_ambassador_application_node_send_notification($node);
}

/**
 * Create a new ambassador application node entry.
 */
function _groups_ambassador_create_application_node($values) {
  $current_user = user_uid_optional_load();
  $n = entity_create('node', array('type' => 'ambassador_application'));
  $n->uid = $current_user->uid;
  $node = entity_metadata_wrapper('node', $n);
  $node->title = t('@name ambassador application - @date',
    array(
      '@name' => $current_user->name,
      '@date' => date('m/d/Y', time()),
  ));
  $node->field_applicant->set($current_user->uid);
  $node->field_region->set($values['region']);
  $node->field_reason->set($values['reason']);
  $node->field_participation->set($values['participation']);
  $node->field_ideas->set($values['ideas']);
  $node->field_collaboration->set($values['collaboration']);
  $node->save();
  return $node;
}

/**
 * Send notification to ambassadors about new application.
 */
function _groups_ambassador_application_node_send_notification($node) {
  $node_url = $GLOBALS['base_url'].'/'.
    drupal_lookup_path('alias',"node/".$node->nid->value());

  $current_user = user_uid_optional_load();
  $admin_user = user_load(1);
  $ambassadors = _groups_ambassador_get_ambassador_list();
  $recipients = groups_ambassador_get_privatemsg_recipients($ambassadors);
  $message = (object)array(
    'author' => $admin_user,
    'format' => 'filtered_html',
    'timestamp' => time(),
    'recipients' => $recipients,
    'has_tokens' => false,
  );

  $message->subject = t('[Ambassador] New ambassador application: @name',
    array('@name' => $current_user->name));

  $message->body = t('A new ambassador application has arrived. <br/><br/>'.
    'Check the link below for details:.<br/><a href="@url">@url</a>',
    array('@url' => $node_url));
  $message = _privatemsg_send($message);
}