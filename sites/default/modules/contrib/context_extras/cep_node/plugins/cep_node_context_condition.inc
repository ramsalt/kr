<?php

/**
 * @file
 * Condition definition to check if user is viewing node page with particular NID
 */

/**
 * Condition to lookup for particular node page
 */
class cep_node_context_condition extends context_condition {
  /**
   * Options form. Provide additional options for your condition.
   */
  function condition_form($context) {
    $values = $this->fetch_from_context($context, 'values');
    return array(
      '#type' => 'textarea',
      '#title' => t('Node NID'),
      '#default_value' => !empty($values) ? implode("\n", $values) : '',
      '#description' => t('Put one node id per line')
    );
  }

  /**
   * Condition form submit handler.
   */
  function condition_form_submit($values) {
    $values = explode("\n", $values);
    $output = array();
    foreach ($values as $value) {
      if (intval($value)) {
        $output[] = intval($value);
      }
    }

    return $output;
  }

  /**
   * Options form. Provide additional options for your condition.
   */
  function options_form($context) {
    $form = array();

    $value = $this->fetch_from_context($context, 'options');
    if (module_exists('translation')) {
      $form = array(
        '#type' => 'checkbox',
        '#title' => t('Look also on translations nids'),
        '#default_value' => $value
      );
    }

    return $form;
  }

  /**
   * Options form submit handler.
   */
  function options_form_submit($values) {
    return $values;
  }

  /**
   * Public method that is called from hooks or other integration
   * points with Drupal.
   */
  function execute($item) {
    foreach ($this->get_contexts() as $context) {
      $nids = $this->fetch_from_context($context, 'values');
      foreach ($nids as $nid) {
        if ($this->match($nid, $item, $context)) {
          $this->condition_met($context, $nid);
          break;
        }
      }
    }
  }

  /**
   * Check if node mets nid
   *
   * @param $nid
   * @param $node
   */
  function match($nid, $item, $context) {
    $node = $item['page_arguments'][0];
    $match_translation = $this->fetch_from_context($context, 'options');
    if ($match_translation) {
      return ($node->nid == $nid || ($node->tnid != 0 && $node->tnid == $nid));
    }
    else {
      return ($node->nid == $nid);
    }
  }
}
