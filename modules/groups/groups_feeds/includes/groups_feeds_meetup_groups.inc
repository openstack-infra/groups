<?php
/**
 * @file
 * Import group data from meetup.com using the meetup API.
 *
 * Variables:
 * - groups_meetup_api_key: the meetup.com API key
 * - groups_sync_meetup_<group-id>: enable / disable data sync with meetup.com
 */

/**
 * Callback to import meetup data through meetup.com API
 */
function groups_feeds_meetup_import() {
  $meetup_api_key = variable_get('groups_meetup_api_key', '');
  if (empty($meetup_api_key)) {
    watchdog('Groups Feeds', 'Variable groups_meetup_api_key is missing.', array(), WATCHDOG_ERROR);
    return FALSE;
  }
  $params = array(
    'sign' => 'true',
    'photo-host' => 'public',
    'key' => $meetup_api_key,
  );
  $wait = 0; // reset limit wait to 0sec
  $meetup_links = groups_feeds_get_meetup_links();
  foreach ($meetup_links as $link) {
    $meetup_name = _groups_feeds_get_meetup_name($link['url']);
    $sync_group = variable_get('groups_sync_meetup_'.$link['nid'], TRUE);
    if ($sync_group) {
      $params['group_urlname'] = $meetup_name;
      $request_url = "https://api.meetup.com/2/groups?";
      foreach ($params as $k => $v) {
        $request_url .= sprintf('&%s=%s', $k, $v);
      }
      $response = _groups_feeds_rlimit_request($request_url, $wait);
      if ($response->code == 200) {
        watchdog('Groups Feeds', 'Meetup.com API Import %meetup [nid:%nid]',
          array('%meetup' => $meetup_name, '%nid' => $link['nid']), WATCHDOG_DEBUG);
        $data = json_decode($response->data);
        $group_node = node_load($link['nid']);
        if (!isset($data->results[0])) {
          watchdog('Groups Feeds', 'Failed to sync meetup group %name: %code %message',
            array(
              '%name' => $meetup_name,
              '%code' => $response->code,
              '%message' => 'empty resultset'), WATCHDOG_ERROR);
        } else {
          // Notify other modules about meetup data import.
          foreach (module_implements('meetup_group_import') as $module) {
            $function = $module . '_meetup_group_import';
            $function($group_node, $data->results[0]);
          }
        }
      } else {
        // log error
        watchdog('Groups Feeds', 'Failed to sync meetup group %name: %code %message',
          array(
            '%name' => $meetup_name,
            '%code' => $response->code,
            '%message' => $response->status_message), WATCHDOG_ERROR);
      }
    }
  }
}
