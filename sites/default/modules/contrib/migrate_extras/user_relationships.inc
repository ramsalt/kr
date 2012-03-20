<?php

/**
 * @file
 * Import User Relationships. 
 * 
 * @todo Lots.
 */

/**
 * Destination class implementing migration into user_relationships table.
 */
class MigrateDestinationUserRelationships extends MigrateDestination {
  public function __construct($rtid) {
    parent::__construct();
    $this->rtid = $rtid;
  }
  
  static public function getKeySchema() {
    return array(
      'rid' => array(
        'type' => 'int',
        'not null' => TRUE,
        'description' => 'Relationship ID',
      ),
    );
  }

  /**
   * Delete a membership.
   *
   * @param $migration
   *  Controlling migration object. Unused here.
   * @param $id
   *  ID to be deleted.
   */
  public function rollback(array $id) {
    migrate_instrument_start(__METHOD__);
    if ($relationship = user_relationships_load(array('rid' => $id['destid1']))) {
      $account = new stdClass;
      user_relationships_delete_relationship(current($relationship), $account);
    }
    migrate_instrument_stop(__METHOD__);
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
    // TODO: handle updates
    
    foreach (array('created_at', 'updated_at') as $property) {
      if (isset($entity->$property)) {
        $entity->$property = Migration::timestamp($entity->$property);
      }
    }
    
    $entity->rtid = $this->rtid;
    
    $op = isset($entity->op) ? $entity->op : 'approve';
    if (user_relationships_save_relationship($entity, $op)) {
      return array($entity->rid);
    }
  }

  public function fields() {
    return array(
        'rid' => 'Relationship ID',
        'requester_id' => '',
        'requestee_id' => '',
        'approved' => '',
        'created_at' => '',
        'updated_at' => '',
        'flags' => '',
        'op' => ''
    );
  }
}
