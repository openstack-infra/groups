<?php
/**
 * @file
 * Displays the group node form.
 */
?>

<div class="registration-lead">
<p>Register your new OpenStack User Group in 3 easy steps, answer the simple questions.
We'll help you to establish your local community and join you into a world-wide network of
OpenStack User Group leaders.</p>
</div>
<h3>What is your User Group's location?</h3>
<?php print drupal_render($form['field_group_location']); ?>

<h3>Share some basic information</h3>
<?php print drupal_render($form['title_field']); ?>
<?php print drupal_render($form['body']); ?>
<h3>Accept Our Terms and Conditions</h3>
<?php print drupal_render($form['accept_terms']); ?>

<?php
  // render the remaining form elements
  print drupal_render_children($form);
?>