<?php

/**
 * @file
 * This class extends the context_condition by implementing the condition for
 * assigning immediate children taxonomy terms of selected taxonomy terms as a context condition.
 */
class cep_immediate_taxonomy_child_context_condition extends context_condition {

  function condition_values() {
    $values = array();
    if (module_exists('taxonomy')) {
      foreach (taxonomy_get_vocabularies() as $vocab) {
        if (empty($vocab->tags)) {
          foreach (taxonomy_get_tree($vocab->vid) as $term) {
            $values[$term->tid] = $term->name;
          }
        }
      }
    }
    return $values;
  }

  function condition_form($context) {
    $form = parent::condition_form($context);
    $form['#type'] = 'select';
    $form['#size'] = 12;
    $form['#multiple'] = TRUE;
    $form['#options'] = taxonomy_form_all();
    return $form;
  }

  /**
   * Execute.
   */
  function execute() {
    if (arg(0) == 'taxonomy' && arg(1) == 'term' && is_numeric(arg(2))) {
      foreach (context_enabled_contexts() as $context) {
        if ($selected_terms = $this->fetch_from_context($context, 'values')) {
          $current_term_parents = taxonomy_get_parents(arg(2));
          foreach ($selected_terms as $key => $value) {
            if (!empty($current_term_parents[$key])) {
              $this->condition_met($context, arg(2));
            }
          }
        }
      }
    }
  }
}
