<?php
/**
 * @file
 *  Feeds parser class to process markdown files with
 *  jekyll like yaml headers.
 */

/**
 * Base class for all exceptions thrown by FeedsMarkdownParse
 */
class FeedsMarkdownException extends Exception {}

class FeedsMarkdownParser extends FeedsParser {

  /**
   * Parse a feed source
   *
   */

  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $result = new FeedsParserResult();
    $raw = $fetcher_result->getRaw();
    if ($fetcher_result instanceof FeedsFileFetcherResult) {
      var_dump($fetcher_result);
    }
    try {
      $markdown = $this->parseMarkdown($raw);
    } catch (FeedsMarkdownException $e) {
      // catch invalid markdown formats here
      return $result;
    }
    $mandatory_fields = array('title', 'body');
    $optional_fields = array('path', 'published');
    $item = array();
    // process mandatory fields
    foreach ($mandatory_fields as $field) {
      if (empty($markdown[$field])) {
        // skip if mandatory field is missing.
        return $result;
      }
      $item[$field] = $markdown[$field];
    }
    // process optional fields
    foreach ($optional_fields as $field) {
      if (isset($markdown[$field])) {
        $item[$field] = $markdown[$field];
      }
    }
    // guid mapping
    if ($fetcher_result instanceof FeedsFileFetcherResult) {
      // Notice: we could implement a better guid mapping here,
      // but actually the file path is a unique identifier for
      // content identification.
      $filePath = $fetcher_result->getFilePath();
      $item['guid'] = $filePath;
    }
    $result->items[] = $item;
    return $result;
  }

  /**
   * Return mapping sources
   *
   */

  public function getMappingSources() {
    return parent::getMappingSources() + array(
      'guid' => array(
        'name' => t('GUID'),
      ),
      'title' => array(
        'name' => t('Title'),
        'description' => t('Title.'),
      ),
      'body' => array(
        'name' => t('Body'),
      ),
      'path' => array(
        'path' => t('Path'),
      ),
      'published' => array(
        'published' => t('Published'),
      ),
    );
  }

  /**
   * Parse a markdown file
   *
   * Markdown format:
   * ---
   * key:value
   * ...
   * ---
   * Markdown payload
   * ...
   *
   * @return
   *   return a key-value representation of the markdown,
   *   including header meta-parameters and body
   */

  public function parseMarkdown($raw) {
    $result = array();
    $header_flag = true;
    $body = '';
    // read from in-memory stream
    $fp = fopen("php://memory", 'r+');
    $stored_exception = null;
    try {
      fputs($fp, $raw);
      rewind($fp);
      // parse header marker, we except --- here
      $line = fgets($fp);
      if ($line != "---\n") {
        throw new FeedsMarkdownException('Missing header mark');
      }
      // process content
      $line = fgets($fp);
      while ($line !== false) {
        if ($header_flag) {
          if ($line == "---\n") {
            $header_flag = false;
          } else {
            if (strpos($line, ':') !== false) {
              list($key, $value) = explode(':', $line);
              $result[trim($key)] = trim($value);
            }
          }
        } else {
          $body .= $line;
        }
        $line = fgets($fp);
      }
    }
    catch (Exception $e) {
      $stored_exception = $e;
    }
    // always close the file handler
    fclose($fp);
    $result['body'] = $body;
    if ($stored_exception) {
      throw $stored_exception;
    }
    return $result;
  }

}