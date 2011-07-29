<?php

class MigrateDateFieldHandler extends MigrateFieldHandler {
  public function __construct() {
    $this->registerTypes(array('date', 'datestamp', 'datetime'));
  }

  public function prepare($entity, array $instance, array $values) {
    // Setup the standard Field API array for saving.
    $delta = 0;
    foreach ($values as $value) {
      // Work from a timestamp
      $timestamp = MigrationBase::timestamp($value);
      // What does the destination field expect?
      if ($instance['type'] == 'datestamp') {
        // UNIX timestamp
        $value = $timestamp;
      }
      elseif ($instance['type'] == 'datetime') {
        // YYYY-MM-DD HH:MM:SS - prevent timezone application
        $value = format_date($timestamp, 'custom', 'Y-m-d H:i', 0);
      }
      elseif ($instance['type'] == 'date') {
        // ISO date: YYYY-MM-DDTHH:MM:SS - prevent timezone application
        $value = format_date($timestamp, 'custom', 'Y-m-dTH:i', 0);
      }
      else {
        // Should never get here
      }

      $return[$delta]['value'] = $value;
      $delta++;
    }
    if (!isset($return)) {
      $return = NULL;
    }
    return $return;
  }
}
