#!/usr/bin/env php
<?php

/**
 * @file
 * Drupal manifest file creation tool. The manifest file represents
 * the release history of a Drupal project or module. This tool
 * helps to build a custom manifest file as the part of the OpenStack
 * CI process.
 */

// initial config settings
$config = array(
  'manifest-url' => 'http://tarballs.openstack.org/groups/7.x',
  'debug' => FALSE,
  'verbose' => FALSE,
  'outfile' => 'manifest.xml',
  'help' => FALSE,
);

// command line argument schema definition
$arg_schema = array(
  'version' => array(
    '#required' => TRUE,
    '#description' => 'release version (7.x-N.N or 7.x-N.x-dev)',
  ),
  'md5' => array(
    '#required' => TRUE,
    '#description' => 'basename of release tar.gz file (eg. groups-N.N.tar.gz)',
  ),
  'releasetar' => array(
    '#required' => TRUE,
    '#description' => 'md5 hash of release tar.gz file',
  ),
  'debug' => array(
    '#required' => FALSE,
    '#description' => 'enable debug messages, defaults to FALSE',
  ),
  'verbose' => array(
    '#required' => FALSE,
    '#description' => 'enable verbouse output, defaults to FALSE',
  ),
  'manifest-url' => array(
    '#required' => FALSE,
    '#description' => 'url of original manifest file',
  ),
  'outfile' => array(
    '#required' => FALSE,
    '#description' => 'write manifest to this file, defaults to manifest.xml',
  ),
  'help' => array(
    '#required' => FALSE,
    '#description' => 'Show the help',
  ),
);

// manifest template
$manifest_template = '<?xml version="1.0" encoding="utf-8"?>
<project xmlns:dc="http://purl.org/dc/elements/1.1/">
  <title>Groups Portal</title>
  <short_name>groups</short_name>
  <type>project_distribution</type>
  <api_version>7.x</api_version>
  <recommended_major>0</recommended_major>
  <supported_majors>0</supported_majors>
  <default_major>0</default_major>
  <project_status>published</project_status>
  <link>https://drupal.org/project/groups</link>
  <terms>
    <term>
      <name>Projects</name>
      <value>Distributions</value>
    </term>
  </terms>
  <releases>
  </releases>
</project>';

// log level constants
define('_LOG_DEBUG_', 'DEBUG');
define('_LOG_INFO_', 'INFO');
define('_LOG_ERROR_', 'ERROR');

/**
 * Write a log message depending on configuration settings.
 *
 * @param  string $type    log level (debug, info, error)
 * @param  string $message log message
 */
function write_log($type, $message) {
  global $config;
  if (($type == 'DEBUG') && ($config['debug'] == FALSE)) {
    // skip if debug mode disabled
    return;
  }
  if (($type == 'INFO') && ($config['verbose'] == FALSE)) {
    // skip if verbose disabled
    return;
  }
  echo sprintf("%s [%s] %s\n", date('c'), $type, $message);
}

/**
 * Validate and decode a Drupal format version string
 * into a key-value array.
 *
 * 7.x-1.0 converted to:
 * array(
 *   'major' => 1,
 *   'patch' => 0,
 * )
 *
 * 7.x-1.x-dev converted to:
 * array(
 *   'major' => 1,
 *   'extra' => 'dev',
 * )
 *
 * @param  string $version version string
 * @return array           decoded version as key value array
 */
function match_version($version) {
  $pattern = '/^7.x-(?P<major>\d+).((?P<patch>\d+)|x-(?P<extra>dev))$/';
  $matches = array();
  if (preg_match($pattern, $version, $matches)) {
    foreach ($matches as $key => $value) {
      if ((is_int($key)) || ($value == NULL)) {
        unset($matches[$key]);
      }
    }
  } else {
    throw new Exception(sprintf('Invalid version number format: %s', $version));
  }
  return $matches;
}

/**
 * Insert or update a release element in project xml.
 *
 * @param  class $xml          project xml as a simplexml object.
 * @param  string $version     release version
 * @param  string $releaseTar  basename of release tar.gz file
 * @param  string $md5         md5 hash of release tar.gz file
 * @param  string $fileSize    file size of release (optional)
 * @param  string $releaseDate release date of the release (optional)
 */
function append_release($xml, $version, $releaseTar, $md5, $fileSize = NULL, $releaseDate = NULL) {
  $downloadUrl = 'http://tarballs.openstack.org/groups/'.$releaseTar;
  // remove previous release entry with same version
  list($element) = $xml->xpath('/project/releases/release/version[. = "'.$version.'"]/parent::*');
  if (!empty($element)) {
    unset($element[0]);
    $verb = 'Override';
  } else {
    $verb = 'Insert';
  }
  write_log(_LOG_INFO_, sprintf('%s a release element [version=%s, releaseTar=%s, md5=%s]',
    $verb, $version, $releaseTar, $md5));
  // add release elements
  $release = $xml->releases->addChild('release');
  $release->addChild('name', 'groups '.$version);
  $release->addChild('version', $version);
  $release->addChild('tag', $version);
  $release->addChild('status', 'published');
  $release->addChild('download_link', $downloadUrl);
  $release->addChild('mdhash', $md5);
  // append version
  $v = match_version($version);
  if (empty($v)) {
    throw new Exception('Invalid version format.');
  }
  foreach ($v as $key => $value) {
    $release->addChild('version_'.$key, $value);
  }
  $files = $release->addChild('files');
  $file = $files->addChild('file');
  $file->addChild('url', $downloadUrl);
  $file->addChild('archive_type', 'tar.gz');
  $file->addChild('variant', 'full');
  $file->addChild('md5', $md5);
}

/**
 * Show the help and construct parameter list by
 * argument schema.
 *
 * @param  array $arg_schema  argument schema
 */
function print_help($arg_schema) {
  echo "Generate Drupal manifest file to represent a project release history.\n\n";
  echo "Example:\n";
  echo "  release-manifest.php --version=7.x-1.0 --releasetar=groups-1.0.tar.gz --md5=c59611415cea4bc6397b1351b2b36b7c\n\n";
  echo "Options:\n";
  foreach ($arg_schema as $key => $value) {
    echo sprintf("  --%-16s  %s\n", $key, $value['#description']);
  }
  echo "\n";
}

/**
 * Parse and validate command line parameters based on
 * predefined argument schema.
 *
 * @param  array $argv       command line arguments
 * @param  array $arg_schema argument schema
 * @return array             parsed parameters
 */
function get_cli_parameters($argv, $arg_schema) {
  $params = array();
  // parse cli arguments
  foreach ($argv as $arg) {
    if (strpos($arg, '--') !== false) {
      list($key, $value) = explode("=",$arg);
      $key = substr($key, 2);
      if (isset($arg_schema[$key]) == FALSE) {
        print_help($arg_schema);
        throw new Exception(sprintf('Invalid command line argument: %s', $key));
      }
      if (isset($key)) {
        $params[$key] = isset($value) ? $value : TRUE;
      }
    }
  }
  if (empty($params['help'])) {
    // check required parameters
    foreach ($arg_schema as $key => $value) {
      if (($value['#required']) && (empty($params[$key]))) {
        print_help($arg_schema);
        throw new Exception(sprintf('Mandatory parameter %s missing.', $key));
      }
    }
  }
  return $params;
}

try {
  // parse cli arguments and merge with config
  $params = get_cli_parameters($argv, $arg_schema);
  $config = array_replace($config, $params);
  if ($config['help']) {
    print_help($arg_schema);
    exit(0);
  }
  if ($config['debug']) {
    write_log(_LOG_DEBUG_, 'Command line args:');
    foreach ($config as $key => $value) {
      write_log(_LOG_DEBUG_, sprintf('  %-16s = %s', $key, (string)$value));
    }
  }
  // load original manifest
  $xml = @simplexml_load_file($config['manifest-url']);
  if (!$xml) {
    write_log(_LOG_INFO_, 'Create a new manifest file, failed to fetch from remote url.');
    $xml = simplexml_load_string($manifest_template);
  }
  append_release($xml, $params['version'], $params['releasetar'], $params['md5']);
  $xml_content = $xml->asXML();
  write_log(_LOG_DEBUG_, sprintf("Generated manifest:\n %s", $xml_content));
  file_put_contents($config['outfile'], $xml_content);
} catch (Exception $e) {
  write_log(_LOG_ERROR_, $e->getMessage());
  exit(1);
}