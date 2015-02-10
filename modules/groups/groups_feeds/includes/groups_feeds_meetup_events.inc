<?php
/**
 * @file
 * Import meetup.com group events through publicly available
 * iCal feeds.
 *
 * Iterate through all group content and fetch the events
 * from the group's meetup.com iCal feed when event sync
 * is enabled for the group.
 *
 * Variables:
 * - groups_sync_event_<group-id>: enable / disable event sync of group
 */

/**
 * Construct meetup.com ical importer
 */
function groups_feeds_meetup_ical_importer() {
  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'ical_feed_importer';
  $feeds_importer->config = array(
    'name' => 'meetup.com events',
    'description' => 'meetup.com event feed importer',
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
      'plugin_key' => 'DateiCalFeedsParser',
      'config' => array(
        'indefinite_count' => '52',
        'until_not_utc' => FALSE,
        'skip_days' => NULL,
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
            'source' => 'DTSTART',
            'target' => 'field_date:start',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'DTEND',
            'target' => 'field_date:end',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'SUMMARY',
            'target' => 'title_field',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'DESCRIPTION',
            'target' => 'body',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'UID',
            'target' => 'guid',
            'unique' => 1,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'event',
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
 * Meetup events import worker.
 *
 * Import events from meetup ical feed, if not disabled in
 * groups_sync_event_<group-id> variable.
 *
 * @param  array $job Associative array of job parameters. When set to
 *   NULL, won't reschedule the job.
 */
function groups_feeds_meetup_events_import($job = NULL) {
  $meetup_links = groups_feeds_get_meetup_links();
  foreach ($meetup_links as $meetup_link) {
    $url = _groups_feeds_join_url($meetup_link['url'], '/events/ical/');
    $feedSource = feeds_source('ical_feed_importer');
    $config = $feedSource->getConfig();
    $config['FeedsHTTPFetcher']['source'] = $url;
    $config['FeedsHTTPFetcher']['nid'] = $meetup_link['nid'];
    $feedSource->setConfig($config);
    if (variable_get('groups_sync_event_'.$meetup_link['nid'], TRUE)) {
      try {
        while (FEEDS_BATCH_COMPLETE != $feedSource->import());
        $feedSource->log('import', 'Import meetup event: !url', array('!url' => $url), WATCHDOG_INFO);
      } catch (Exception $e) {
        $feedSource->log('import', 'Failed to import feed: !url', array('!url' => $url), WATCHDOG_ERROR);
      }
    }
    _groups_feeds_cleanup($feedSource);
  }
}