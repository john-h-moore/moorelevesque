<?php
/**
 * @file
 * rsvp.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function rsvp_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_rsvp:user/ac.
  $menu_links['main-menu_rsvp:user/ac'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'user/ac',
    'router_path' => 'user/ac',
    'link_title' => 'RSVP',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_rsvp:user/ac',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('RSVP');

  return $menu_links;
}
