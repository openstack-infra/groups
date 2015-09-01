<?php
/**
 * @file
 * groups_messages.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function groups_messages_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pm_email_notify_body';
  $strongarm->value = 'Hi [privatemsg_message:recipient],

This is an automatic reminder from the site [site:name]. You have received a new message from [privatemsg_message:author].

To read your message, follow this link:
[privatemsg_message:url]

If you don\'t want to receive these emails again, change your preferences here:
[privatemsg_message:recipient:edit-url]';
  $export['pm_email_notify_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pm_email_notify_default';
  $strongarm->value = 1;
  $export['pm_email_notify_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pm_email_notify_from';
  $strongarm->value = '';
  $export['pm_email_notify_from'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pm_email_notify_subject';
  $strongarm->value = 'New message in [privatemsg_message:subject]';
  $export['pm_email_notify_subject'] = $strongarm;

  return $export;
}
