<?php

/**
 * @file
 * Support for the Pathauto module.
 */

/**
 * Field handler.
 */
class MigratePathautoHandler extends MigrateDestinationHandler {
  public function __construct() {
    $this->registerTypes(array('node', 'user', 'taxonomy_term'));
  }

  /**
   * Make the destination field visible.
   */
  public function fields() {
    if (module_exists('pathauto')) {
      return array(
        'pathauto_perform_alias' =>
          t('Pathauto: Perform aliasing (set to 0 to prevent alias generation during migration'),
      );
    }
    else {
      return array();
    }
  }
}
