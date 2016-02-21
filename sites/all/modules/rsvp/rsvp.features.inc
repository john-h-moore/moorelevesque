<?php
/**
 * @file
 * rsvp.features.inc
 */

/**
 * Implements hook_views_api().
 */
function rsvp_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function rsvp_node_info() {
  $items = array(
    'manual_rsvp' => array(
      'name' => t('Manual RSVP'),
      'base' => 'node_content',
      'description' => t('Use to create RSVP on behalf of a guest (e.g., phone/email/verbal RSVP)'),
      'has_title' => '1',
      'title_label' => t('Last Name'),
      'help' => '',
    ),
    'rsvp' => array(
      'name' => t('RSVP'),
      'base' => 'node_content',
      'description' => t('RSVP content type - contains names of people who RSVP\'d'),
      'has_title' => '1',
      'title_label' => t('Last Name'),
      'help' => t('<strong>If you need to change your RSVP for any reason</strong> please call 508-380-2743 (Christa), 303-718-9787 (John), or email us at christa@moorelevesque.com or john@moorelevesque.com.
<br>
<strong>If there are multiple last names for your party</strong>, please choose one - we know who you are. :-)
<br>
<strong>If only some of your party are attending</strong>, please only fill in those names.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
