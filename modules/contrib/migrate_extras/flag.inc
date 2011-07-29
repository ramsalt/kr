<?php

/**
 * @file
 * Flag module integration
 */

/**
 * Destination class implementing when you want just an insert into flag_content table.
 */
class MigrateDestinationFlagSimple extends MigrateDestination {
  public function __construct($fid) {
    parent::__construct();
    $this->fid = $fid;
  }
  
  static public function getKeySchema() {
    return array(
      'fcid' => array(
        'type' => 'int',
        'not null' => TRUE,
      ),
    );
  }

  /**
   * Delete a membership.
   *
   * @param $id
   *  IDs to be deleted.
   */
  public function bulkRollback(array $ids) {
    migrate_instrument_start(__METHOD__);
    db_delete('flag_content')
      ->condition('fcid', $ids, 'IN');
    migrate_instrument_stop(__METHOD__);
  }

  /**
   * Import a single flag_content.
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
    if (isset($entity->timestamp)) {
      $entity->timestamp = Migration::timestamp($entity->timestamp);
    }
    
    $entity->fid = $this->fid;
    
    if (!empty($entity->fcid)) {
      $return = drupal_write_record('flag_content', $entity, 'fcid');  
    }
    else {
      $return = drupal_write_record('flag_content', $entity);
    }
    if ($return) {
      return array($entity->fcid);
    }
  }

  public function fields() {
    return array(
        'fcid' => 'Flag content ID',
        'fid' => 'Flag ID',
        'content_type' => '',
        'content_id' => '',
        'uid' => 'User ID',
        'timestamp' => '',
    );
  }
}
