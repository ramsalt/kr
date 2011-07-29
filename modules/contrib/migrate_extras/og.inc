<?php

/**
 * @file
 * Import Organic group memberships.
 */

/**
 * Destination class implementing migration into og_uid table.
 */
class MigrateDestinationOGMembership extends MigrateDestination {

  static public function getKeySchema() {
    return array(
      'gid' => array(
        'type' => 'int',
        'not null' => TRUE,
        'description' => 'NID of group',
      ),
      'uid' => array(
        'type' => 'int',
        'not null' => TRUE,
        'description' => 'UID of member',
      ),
    );
  }

  /**
   * Delete a membership.
   * @param $id
   *  ID to be deleted.
   */
  public function rollback(array $id) {
    migrate_instrument_start('OGMembership bulkRollback');
    og_delete_subscription($id['gid'], $id['uid']);
    migrate_instrument_stop('OGMembership bulkRollback');
  }

  /**
   * Import a single membership.
   *
   * @param $entity
   *  Object object to build. Prefilled with any fields mapped in the Migration.
   * @param $row
   *  Raw source data object - passed through to prepare/complete handlers.
   * @return array
   *  Array of key fields of the object that was saved if
   *  successful. FALSE on failure.
   */
  public function import(stdClass $entity, stdClass $row) {
    if (empty($entity->gid)) {
      throw new MigrateException('Missing $entity->gid');
    }
    if (empty($entity->uid)) {
      throw new MigrateException('Missing $entity->uid');
    }
    
    // TODO
    $args = array(
        'is_active' => $entity->is_active,
        'is_admin' => $entity->is_admin,
        'created' => $entity->created,
    );
    og_save_subscription($entity->gid, $entity->uid, $args);

    // No failure handling in OG
    return array($entity->gid, $entity->uid);
  }

  public function fields() {
    return array(
        'gid' => 'Group node id',
        'uid' => 'User ID',
        'is_active' => 'User\'s group membership is active (1) or pending (0)',
        'is_admin' => 'Is member an administrator in this group',
        'created' => 'Create date for this membership. Defaults to time()',
    );
  }

}
