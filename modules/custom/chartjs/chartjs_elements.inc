<?php

/**
 * @file
 * Define custom chartjs form elements.
 */

/**
 * Implement hook_element_info()
 */
function _chartjs_element_info() {
  $types['chart'] = array(
    '#input' => TRUE,
    '#theme' => 'chartjs_chart',
    '#theme_wrappers' => array('form_element'),
    '#pre_render' => array('_chartjs_chart_pre_render'),
  );
  return $types;
}

/**
 * Define chartjs theme callbacks.
 */
function _chartjs_theme($existing, $type, $theme, $path) {
  return array(
    'chartjs_chart' => array(
      'render element' => 'element',
      'file' => 'chartjs_elements.inc',
    ),
  );
}

/**
 * Implement chart pre render callback.
 */
function _chartjs_chart_pre_render($element) {
  libraries_load('chartjs');
  $name = isset($element['#name']) ? $element['#name'] : "chart";
  $chart_type = isset($element['#chart_type']) ? $element['#chart_type'] : "bar";
  $element['#attached']['js'] = array(
    drupal_get_path('module', 'chartjs').'/js/chart_elements.js',
    array(
      'data' => array(
        'chart_'.$name => array(
          'labels' => $element['#labels'],
          'datasets' => $element['#datasets'],
        ),
        'chart_'.$name.'_options' => $element['#options'],
        'chart_'.$name.'_type' => $chart_type,
      ),
      'type' => 'setting',
    )
  );
  return $element;
}

/**
 * Implements chart theme callback.
 */
function theme_chartjs_chart($variables) {
  $name = isset($variables['element']['#name']) ? $variables['element']['#name'] : 'chart';
  $output = '<div class="chart-container">';
  $output .= sprintf('<canvas id="%s" ', $name);
  if (isset($variables['element']['#height'])) {
    $output .= sprintf('height="%s"', $variables['element']['#height']);
  }
  $output .= '></canvas></div>';
  // $output = sprintf('<div class="chart-container"><canvas id="%s" height="400px"></canvas></div>', $name);
  return $output;
}