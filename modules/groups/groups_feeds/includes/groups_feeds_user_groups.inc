<?php
/**
 * @file
 * Import group data from an external groups.json file.
 *
 * Variables:
 * - groups_feeds_groups_json_url: url of groups json file.
 */

/**
 * Constructs a user group feed importer.
 */
function groups_feeds_groups_importer() {
  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'user_group_feed_importer';
  $feeds_importer->config = array(
    'name' => 'User group feed importer',
    'description' => 'Import user group data from json',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsJSONPathParser',
      'config' => array(
        'context' => '$.groups.*',
        'sources' => array(
          'jsonpath_parser:3' => 'id',
          'jsonpath_parser:0' => 'title',
          'jsonpath_parser:1' => 'location',
          'jsonpath_parser:2' => 'attributes',
        ),
        'debug' => array(
          'options' => array(
            'context' => 0,
            'jsonpath_parser:3' => 0,
            'jsonpath_parser:0' => 0,
            'jsonpath_parser:1' => 0,
            'jsonpath_parser:2' => 0,
          ),
        ),
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'jsonpath_parser:3',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'jsonpath_parser:0',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'jsonpath_parser:1',
            'target' => 'field_group_location',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'jsonpath_parser:2',
            'target' => 'field_resource_links',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'group',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  return $feeds_importer;
}

/**
 * User group data import worker, imports data from groups-static-pages repo's
 * groups.json file.
 *
 * @param  array $job Associative array of job parameters. When set to
 *   NULL, won't reschedule the job.
 */
function groups_feeds_user_groups_import($job = NULL) {
  $url = variable_get('groups_feeds_groups_json_url', 'https://raw.githubusercontent.com/openstack-infra/groups-static-pages/master/groups.json');
  watchdog('groups_feeds', 'start user groups import', array(), WATCHDOG_INFO);
  $feedSource = feeds_source('user_group_feed_importer');
  $config = $feedSource->getConfig();
  $config['FeedsHTTPFetcher']['source'] = $url;
  $feedSource->setConfig($config);
  try {
    while (FEEDS_BATCH_COMPLETE != $feedSource->import());
    $feedSource->log('import', 'Import user groups: !source', array('!source' => $url), WATCHDOG_INFO);
  } catch (Exception $e) {
    watchdog_exception('Groups Feeds', $e);
  }
  _groups_feeds_cleanup($feedSource);
}