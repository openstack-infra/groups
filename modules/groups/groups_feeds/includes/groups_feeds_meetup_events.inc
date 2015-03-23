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
          5 => array(
            'source' => 'LOCATION',
            'target' => 'field_address:data',
            'unique' => FALSE,
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

/**
 * Returns the lookup table of US states.
 */
function _us_states_get_predefined_list() {
  static $us_states;

  if (isset($us_states)) {
    return $us_states;
  }
  $t = get_t();

  $us_states = array(
    'AL' => $t('Alabama'),
    'AK' => $t('Alaska'),
    'AZ' => $t('Arizona'),
    'AR' => $t('Arkansas'),
    'CA' => $t('California'),
    'CO' => $t('Colorado'),
    'CT' => $t('Connecticut'),
    'DE' => $t('Delaware'),
    'DC' => $t('District Of Columbia'),
    'FL' => $t('Florida'),
    'GA' => $t('Georgia'),
    'HI' => $t('Hawaii'),
    'ID' => $t('Idaho'),
    'IL' => $t('Illinois'),
    'IN' => $t('Indiana'),
    'IA' => $t('Iowa'),
    'KS' => $t('Kansas'),
    'KY' => $t('Kentucky'),
    'LA' => $t('Louisiana'),
    'ME' => $t('Maine'),
    'MD' => $t('Maryland'),
    'MA' => $t('Massachusetts'),
    'MI' => $t('Michigan'),
    'MN' => $t('Minnesota'),
    'MS' => $t('Mississippi'),
    'MO' => $t('Missouri'),
    'MT' => $t('Montana'),
    'NE' => $t('Nebraska'),
    'NV' => $t('Nevada'),
    'NH' => $t('New Hampshire'),
    'NJ' => $t('New Jersey'),
    'NM' => $t('New Mexico'),
    'NY' => $t('New York'),
    'NC' => $t('North Carolina'),
    'ND' => $t('North Dakota'),
    'OH' => $t('Ohio'),
    'OK' => $t('Oklahoma'),
    'OR' => $t('Oregon'),
    'PA' => $t('Pennsylvania'),
    'RI' => $t('Rhode Island'),
    'SC' => $t('South Carolina'),
    'SD' => $t('South Dakota'),
    'TN' => $t('Tennessee'),
    'TX' => $t('Texas'),
    'UT' => $t('Utah'),
    'VT' => $t('Vermont'),
    'VA' => $t('Virginia'),
    'WA' => $t('Washington'),
    'WV' => $t('West Virginia'),
    'WI' => $t('Wisconsin'),
    'WY' => $t('Wyoming'),
    ' ' => $t('--'),
    'AA' => $t('Armed Forces (Americas)'),
    'AE' => $t('Armed Forces (Europe, Canada, Middle East, Africa)'),
    'AP' => $t('Armed Forces (Pacific)'),
    'AS' => $t('American Samoa'),
    'FM' => $t('Federated States of Micronesia'),
    'GU' => $t('Guam'),
    'MH' => $t('Marshall Islands'),
    'MP' => $t('Northern Mariana Islands'),
    'PW' => $t('Palau'),
    'PR' => $t('Puerto Rico'),
    'VI' => $t('Virgin Islands'),
  );

  return $us_states;
}

/**
 * Lookup meetup.com location based on US state.
 */
function _match_us_location($elements) {
  $us_states = _us_states_get_predefined_list();
  $state_part = array_shift($elements);
  if ($state_part == 'USA') {
    $state_part = array_shift($elements);
  }
  if (strlen($state_part == 2)) {
    $state_code = $state_part;
  } else {
    $state_code = reset(explode(' ', $state_part));
  }
  if (($state_code != NULL) && (isset($us_states[$state_code]))) {
    $city = array_shift($elements);
    $result['city'] = sprintf('%s, %s', $city, $state_code);
    $result['address'] = implode(', ', array_reverse($elements));
    $result['country'] = 'United States';
    return $result;
  }
  return FALSE;
}

/**
 * Lookup meetup.com location based on country name.
 */
function _match_location_by_country($elements) {
  $country_names = _country_names_get_predefined_list();
  $country = array_shift($elements);
  if (($country != NULL) && isset($country_names[$country])) {
    $result['city'] = array_shift($elements);
    $result['address'] = implode(', ', array_reverse($elements));
    $result['country'] = $country;
    return $result;
  }
  return FALSE;
}

/**
 * Split address elements by comma separator and returns the proper
 * array representation. This callback also removes whitespace.
 *
 * @param  string $address_part
 *   meetup.com address representation as a text
 * @return array
 *   address parts as array elements
 */
function _normalize_address_elements($address_part) {
  $address_part = stripslashes($address_part);
  $address_elements = explode(', ', rtrim($address_part, ')'));
  foreach ($address_elements as $k => $v) {
    $address_elements[$k] = trim($v);
  }
  return array_reverse($address_elements);
}

/**
 * Parse a meetup location string.
 *
 * Meetup location field format:
 * %venue (%address, %city, %country)
 *
 * @param  string $location
 *   meetup location representation as a string
 * @return array
 *   returns the parsed location elements:
 *   Array(
 *     ['venue'] => '',
 *     ['address'] => '',
 *     ['city'] => '',
 *     ['country'] => '',
 *   )
 */
function _parse_meetup_location($location) {
  list($venue_part, $address_part) = @explode('(', $location, 2);
  if ($address_part) {
    $address_elements = _normalize_address_elements($address_part);
    $rules = array(
      '_match_us_location',
      '_match_location_by_country',
    );
    foreach ($rules as $rule) {
      $args = array($address_elements);
      if ($result = call_user_func_array($rule, $args)) {
        break;
      }
    }
  }
  $result['venue'] = trim($venue_part);
  return $result;
}

/**
 * Return the reverse mapped array of countries,
 * where the key represents the name of the country
 * and value represents to ISO country code.
 *
 * @return
 *   Array representation of countries.
 */
function _country_names_get_predefined_list() {
  static $country_names;

  if (isset($country_names)) {
    return $country_names;
  }
  include_once DRUPAL_ROOT . '/includes/iso.inc';
  $countries = _country_get_predefined_list();
  foreach ($countries as $k => $v) {
    $country_names[$v] = $k;
  }
  return $country_names;
}

/**
 * Return the ISO code of the country based
 * on country name.
 * @param  $name
 *   name of the country
 * @return
 *   ISO country code, or NULL if not found.
 */
function _country_code_by_name($name) {
  $country_names = _country_names_get_predefined_list();
  return $country_names[$name];
}