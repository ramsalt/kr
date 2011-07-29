<?php

/**
 * @file
 * Support for titles into the Page Title module.
 */

class MigratePageTitleNodeHandler extends MigrateDestinationHandler {
  public function __construct() {
    $this->registerTypes(array('node'));
  }

  /**
   * Make the destination field visible.
   */
  public function fields() {
    if (module_exists('page_title')) {
      return array(
        'page_title' => t('Page Title: Title for &lt;title&gt; tag'),
      );
    }
    else {
      return array();
    }
  }
}
