<?php
/**
 * @file
 * Openstack Front panel implementation to present a Panels layout.
 */
$panel_prefix = isset($panel_prefix) ? $panel_prefix : '';
$panel_suffix = isset($panel_suffix) ? $panel_suffix : '';
?>
<div class="openstack-front panel-display clearfix" <?php if (!empty($css_id)): print "id=\"$css_id\""; endif; ?>>
  <?php if ($content['os_top']): ?>
    <div class="region openstack-front-top region-conditional-stack">
      <div class="region-inner clearfix">
        <?php print $content['os_top']; ?>
      </div>
    </div>
  <?php endif; ?>

  <div class="openstack-front-container">
    <div class="region region-openstack-front-top-first">
      <div class="region-inner clearfix">
        <?php print $content['os_top_left']; ?>
      </div>
    </div>
    <div class="region region-openstack-front-top-second">
      <div class="region-inner clearfix">
        <?php print $content['os_top_right']; ?>
      </div>
    </div>
  </div>

  <div class="openstack-front-container">
    <div class="region region-openstack-front-first">
      <div class="region-inner clearfix">
        <?php print $content['os_left']; ?>
      </div>
    </div>
    <div class="region region-openstack-front-second">
      <div class="region-inner clearfix">
        <?php print $content['os_center']; ?>
      </div>
    </div>
    <div class="region region-openstack-front-third">
      <div class="region-inner clearfix">
        <?php print $content['os_right']; ?>
      </div>
    </div>
  </div>

  <?php if ($content['os_middle']): ?>
    <div class="region openstack-front-middle region-conditional-stack">
      <div class="region-inner clearfix">
        <?php print $content['os_middle']; ?>
      </div>
    </div>
  <?php endif; ?>

  <div class="openstack-front-container">
    <div class="region region-openstack-front-bottom-first">
      <div class="region-inner clearfix">
        <?php print $content['os_bottom_left']; ?>
      </div>
    </div>
    <div class="region region-openstack-front-bottom-second">
      <div class="region-inner clearfix">
        <?php print $content['os_bottom_right']; ?>
      </div>
    </div>
  </div>

  <?php if ($content['os_bottom']): ?>
    <div class="region openstack-front-bottom region-conditional-stack">
      <div class="region-inner clearfix">
        <?php print $content['os_bottom']; ?>
      </div>
    </div>
  <?php endif; ?>
</div>