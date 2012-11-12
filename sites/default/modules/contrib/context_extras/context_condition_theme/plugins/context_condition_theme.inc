<?php

/**
 * Expose current language as a context condition.
 */
class context_condition_theme extends context_condition {
  function condition_values() {
    $themes = array();
    foreach (list_themes() as $name => $theme) {
      $themes[$name] = $theme->info['name'];
    }
    return $themes;
  }

  function execute($value) {
    foreach ($this->get_contexts($value) as $context) {
      $this->condition_met($context, $value);
    }
  }
}
