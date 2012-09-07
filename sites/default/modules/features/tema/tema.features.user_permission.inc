<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function tema_user_default_permissions() {
  $permissions = array();

  // Exported permission: create tema content
  $permissions['create tema content'] = array(
    'name' => 'create tema content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'editor',
      '2' => 'web editor',
    ),
  );

  // Exported permission: delete any tema content
  $permissions['delete any tema content'] = array(
    'name' => 'delete any tema content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'editor',
      '2' => 'web editor',
    ),
  );

  // Exported permission: delete own tema content
  $permissions['delete own tema content'] = array(
    'name' => 'delete own tema content',
    'roles' => array(),
  );

  // Exported permission: edit any tema content
  $permissions['edit any tema content'] = array(
    'name' => 'edit any tema content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'editor',
      '2' => 'web editor',
    ),
  );

  // Exported permission: edit own tema content
  $permissions['edit own tema content'] = array(
    'name' => 'edit own tema content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'editor',
      '2' => 'web editor',
    ),
  );

  return $permissions;
}
