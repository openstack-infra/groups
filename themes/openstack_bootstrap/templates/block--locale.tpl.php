<section id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> clearfix collapse"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <h2><?php print t('Select language'); ?></h2>
  <?php print render($title_suffix); ?>

  <?php print $content ?>

</section> <!-- /.block -->