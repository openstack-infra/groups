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

<?php dpm($fields); ?>

<div class="event--large-teaser">
  <div class="container-header">
    <h3><?php print $fields['title_field']->content; ?></h3>
  </div>
  <div class="container-first">
    <div class="field-body"><?php print $fields['body']->content; ?></div>
  </div>
  <div class="container-second">
    <div class="field-date"><?php
      // TODO: rewrite this part into a custom date field formatter.
      $date_str = $fields['field_date']->content;
      $date_str = str_replace('<div class="field-content">', '<div class="field-content"><div class="date-part">', $date_str);
      $date_str = str_replace(',', '</div>', $date_str);
      print $date_str;
    ?></div>
    <div class="field-capacity"><?php print $fields['capacity_used']->content; ?></div>
    <div class="field-comment-count"><?php print $fields['comment_count']->content; ?></div>
  </div>
  <div class="container-footer">
  </div>
</div>