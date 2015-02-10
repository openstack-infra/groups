<?php
/**
 * @file
 * Import static pages from a directory holding markdown files.
 *
 * Variables:
 * - groups_feeds_markdown_directory: markdown file directory.
 */

/**
 * Construct static pages feed importer
 */
function groups_feeds_static_pages_importer() {
  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'static_page_import';
  $feeds_importer->config = array(
    'name' => 'Static page import',
    'description' => 'Import page nodes from markdown file.',
    'fetcher' => array(
      'plugin_key' => 'feeds_fetcher_directory_fetcher',
      'config' => array(
        'recursive' => 1,
        'directory' => 'public://feeds',
        'filemask' => '/\\.md$/',
        'updated_files' => 1,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'MarkdownParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'title',
            'target' => 'title_field',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'body',
            'target' => 'body',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'path',
            'target' => 'path_alias',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'markdown',
        'skip_hash_check' => 0,
        'bundle' => 'page',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 1,
  );
  return $feeds_importer;
}

/**
 * Static pages import worker.
 *
 * @param  array $job Associative array of job parameters. When set to
 *   NULL, won't reschedule the job.
 */
function groups_feeds_static_pages_import($job = NULL) {
  watchdog('groups_feeds', 'start static page import', array(), WATCHDOG_INFO);
  $feedSource = feeds_source('static_page_import');
  $config = $feedSource->getConfig();
  $directory = variable_get('groups_feeds_markdown_directory', NULL);
  if (empty($directory)) {
    watchdog('Groups Feeds', 'Variable groups_feeds_markdown_directory missing.', array(), WATCHDOG_ERROR);
    return FALSE;
  }
  $config['feeds_fetcher_directory_fetcher']['source'] = $directory;
  $config['feeds_fetcher_directory_fetcher']['feed_files_fetched'] = array();
  $feedSource->setConfig($config);
  try {
    while (FEEDS_BATCH_COMPLETE != $feedSource->import());
    $feedSource->log('import', 'Import static page: !source', array('!directory' => $directory), WATCHDOG_INFO);
  } catch (Exception $e) {
    watchdog_exception('Groups Feeds', $e);
  }
  _groups_feeds_cleanup($feedSource);
}