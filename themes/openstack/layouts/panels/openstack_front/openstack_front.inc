<?php

/**
 * Implementation of hook_panels_layouts()
 * @return multitype:
 */

function openstack_openstack_front_panels_layouts() {
  $items['openstack_front'] = array(
    'title' => t('Openstack Front'),
    'category' => t('Openstack Panels'),
    'icon' => 'front.png',
    'theme' => 'openstack_front',
    'admin css' => 'openstack_front.admin.css',
    'regions' => array(
      'os_top' => t('Top (Conditional)'),
      'os_top_left' => t('Top Left'),
      'os_top_right' => t('Top Right'),
      'os_left' => t('Left'),
      'os_center' => t('Center'),
      'os_right' => t('Right'),
      'os_middle' => t('Middle (Conditional)'),
      'os_bottom_left' => t('Bottom Left'),
      'os_bottom_right' => t('Bottom Right'),
      'os_bottom' => t('Bottom (Conditional)'),
    ),
  );
  return $items;
}