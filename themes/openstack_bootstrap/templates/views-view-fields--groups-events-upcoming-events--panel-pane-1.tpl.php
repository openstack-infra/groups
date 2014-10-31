<?php
/**
 * @file
 * Template override for upcoming events view, groups pane.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @see views-views-fields.tpl.php
 */
?>

<div class="event--large-teaser">
  <div class="container-header">
    <h3><?php print $fields['title_field']->content; ?></h3>
  </div>
  <div class="container-first">
    <div class="field-date"><?php print $fields['field_date']->content; ?></div>
    <div class="field-venue"><?php print $fields['field_venue_name']->content; ?> (<?php print $fields['field_address']->content; ?>)</div>
    <div class="field-body"><?php print $fields['body']->content; ?></div>
  </div>
  <div class="container-second">
    <div class="field-capacity"><?php print $fields['capacity_used']->content; ?></div>
    <div class="field-comment-count"><?php print $fields['comment_count']->content; ?></div>
  </div>
  <div class="container-footer">
  </div>
</div>