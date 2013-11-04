<?php

/**
 * Hiding Content and Printing it Separately
 *
 * Use the hide() function to hide fields and other content, you can render it
 * later using the render() function. Install the Devel module and use
 * <?php print dsm($content); ?> to find variable names to hide() or render().
 */
hide($content['comments']);
hide($content['links']);
hide($content['report_link']);
hide($content['field_date']);
hide($content['field_address']);
//hide($content['submitted']);
//$display_submitted = FALSE;
// $keys = array_keys($content);
//echo "<pre>";print_r($content['field_date']);
//die('xxx');
?>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>

  <?php if ($title && !$page): ?>
    <header>
      <?php if ($title): ?>
          <a href="<?php print $node_url; ?>" rel="bookmark"><?php print $title; ?></a>
      <?php endif; ?>
    </header>
  <?php endif; ?>

  <?php print $display_submitted; ?>
  <?php if($display_submitted): ?>
    <footer<?php print $footer_attributes; ?>>
      <p class="author-datetime"><?php print $submitted; ?></p>
    </footer>
  <?php endif; ?>

  <div<?php print $content_attributes; ?>>
    <?php print $user_picture; ?>
    <?php print render($content['field_date']); ?> - <?php print render($content['field_address']); ?>
    <?php print render($content); ?>
  </div>

  <?php if ($links = render($content['links'])): ?>
    <nav<?php print $links_attributes; ?>><?php print $links; ?></nav>
  <?php endif; ?>

  <?php print render($content['report_link']); ?>

</article>
<?php if (isset($content['comments']['comments'])): ?>
<div class="commons-pod commons-pod-comments">
  <?php print render($content['comments']); ?>
  <?php print render($title_suffix); ?>
</div>
<?php endif; ?>