<?php
/**
 * @file
 * rsvp.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function rsvp_user_default_roles() {
  $roles = array();

  // Exported role: Guest.
  $roles['Guest'] = array(
    'name' => 'Guest',
    'weight' => 3,
  );

  return $roles;
}
