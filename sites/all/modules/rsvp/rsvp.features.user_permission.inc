<?php
/**
 * @file
 * rsvp.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function rsvp_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create rsvp content'.
  $permissions['create rsvp content'] = array(
    'name' => 'create rsvp content',
    'roles' => array(
      'Guest' => 'Guest',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any rsvp content'.
  $permissions['delete any rsvp content'] = array(
    'name' => 'delete any rsvp content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own rsvp content'.
  $permissions['delete own rsvp content'] = array(
    'name' => 'delete own rsvp content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any rsvp content'.
  $permissions['edit any rsvp content'] = array(
    'name' => 'edit any rsvp content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own rsvp content'.
  $permissions['edit own rsvp content'] = array(
    'name' => 'edit own rsvp content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
