<?php
/**
 * @file
 * Drush command file
 */

/**
 * Implements hook_drush_command().
 */
function webform_export_drush_command() {
  $items['webform_export'] = array(
    'description' => 'Export Webform submitted data.', 
    'aliases' => array('webformexp')
  );

  return $items;
}

function drush_webform_export() {
  if (module_load_include('inc', 'webform', 'includes/webform.report')) {
    drush_log('Webform module loaded.', 'ok');
  } else {
    drush_log('Problem loading Webform report functions. Be sure Webform module is installed.', 'error');
  }
}