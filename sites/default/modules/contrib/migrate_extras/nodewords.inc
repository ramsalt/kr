<?php

/**
 * @file
 * Support for importing META information into the Nodewords module.
 */

class MigrateNodewordsNodeHandler extends MigrateDestinationHandler {
  public function __construct() {
    $this->registerTypes(array('node'));
  }

  /**
   * Make the destination fields visible. Prefixes added to avoid potential
   * conflict with other modules.
   */
  public function fields() {
    if (module_exists('nodewords')) {
      return array(
        'nodewords_abstract' => t('Nodewords: Abstract'),
        'nodewords_canonical' => t('Nodewords: Canonical'),
        'nodewords_copyright' => t('Nodewords: Copyright'),
        'nodewords_description' => t('Nodewords: Description'),
        'nodewords_keywords' => t('Nodewords: Keywords'),
        'nodewords_revisit-after' => t('Nodewords: Revisit After'),
        'nodewords_robots' => t('Nodewords: Robots'),
      );
    }
    else {
      return array();
    }
  }

  /**
   * Move the nodewords fields into the appropriate structure for the nodewords
   * module to handle them on update/insert.
   */
  public function prepare($node, stdClass $row) {
    if (module_exists('nodewords')) {
      foreach ($this->fields() as $full_field => $label) {
        if (isset($node->$full_field)) {
          $field = substr($full_field, strlen('nodewords_'));
          $node->nodewords[$field]['value'] = $node->$full_field;
          unset($node->$full_field);
        }
      }
    }
  }
}
