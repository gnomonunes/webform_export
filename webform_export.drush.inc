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
    'aliases' => array('webformexp'),
    'arguments' => array(
      'nid' => 'The node id of the webform you want to export the results from.'
    )
  );

  return $items;
}

function drush_webform_export($nid = null) {

  if (!$nid) {
    drush_log('You need to pass the node id of the webform you want to export the results from.', 'error');
    return;
  } elseif (!is_int($nid)) {
    drush_log('The argument you should pass is the node id of the webform you want to export the results from.', 'error');
    return;
  }

  if (module_load_include('inc', 'webform', 'includes/webform.report')) {
    drush_log('Webform module loaded.', 'ok');
  } else {
    drush_log('Problem loading Webform report functions. Be sure Webform module is installed.', 'error');
  }
}