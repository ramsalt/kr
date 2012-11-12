<?php

/**
 * @file
 * This class extends the context_condition by implementing the condition for
 * assigning all paths except for the following paths provided by the user
 */
class cep_negate_path_context_condition extends context_condition {
  /**
   * Omit condition values. We will provide a custom input form for our conditions.
   */
  function condition_values() {
    return array();
  }

  /**
   * Condition form.
   */
  function condition_form($context) {
    $form = parent::condition_form($context);
    unset($form['#options']);

    $form['#type'] = 'textarea';
    $form['#default_value'] = implode("\n", $this->fetch_from_context($context, 'values'));
    return $form;
  }

  /**
   * Condition form submit handler.
   */
  function condition_form_submit($values) {
    $parsed = array();
    $items = explode("\n", $values);
    if (!empty($items)) {
      foreach ($items as $v) {
        $v = trim($v);
        if (!empty($v)) {
          $parsed[$v] = $v;
        }
      }
    }
    return $parsed;
  }

  /**
   * Execute.
   */
  function execute() {
    $current_path = drupal_get_path_alias($_GET['q']);
    foreach (context_enabled_contexts() as $context) {
      if ($paths = $this->fetch_from_context($context, 'values')) {
        $all_conditions_met = TRUE;
        foreach ($paths as $path) {
          $path_match = FALSE;
          if ($path_match = drupal_match_path($current_path, $path)) {
            $all_conditions_met = FALSE;
          }
          elseif ($current_path != $_GET['q'] && drupal_match_path($_GET['q'], $path)) {
            $all_conditions_met = FALSE;
          }
        }
        if ($all_conditions_met) {
          $this->condition_met($context, $path);
        }
      }
    }
  }
}
