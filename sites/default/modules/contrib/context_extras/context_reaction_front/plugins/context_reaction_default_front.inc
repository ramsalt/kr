<?php

/**
 * Expose the site_frontpage variable as a context reaction.
 */
class context_reaction_default_front extends context_reaction {

  /**
   * Display the text field for the new site front page
   */
  function options_form($context) {
    $values = $this->fetch_from_context($context);

    $form = array(
      '#tree' => TRUE,
      '#title' => t('Front page'),
      'site_frontpage' => array(
        '#type' => 'textfield',
        '#title' => t('Default front page'),
        '#description' => t('Enter the path for the default front page.'),
        '#default_value' => isset($values['site_frontpage']) ? $values['site_frontpage'] : variable_get('site_frontpage', 'node'),
      ),
    );
    return $form;
  }

  /**
   * Validate the front page path.
   * This is an exact copy of the code from system.admin.inc
   */
  function options_form_validate($form, &$form_state) {
    $item = array('link_path' => $form_state['values']['site_frontpage']);
    $normal_path = drupal_get_normal_path($item['link_path']);
    if ($item['link_path'] != $normal_path) {
      drupal_set_message(t('The menu system stores system paths only, but will use the URL alias for display. %link_path has been stored as %normal_path', array('%link_path' => $item['link_path'], '%normal_path' => $normal_path)));
      $item['link_path'] = $normal_path;
    }
    if (!empty($item) && !menu_valid_path($item)) {
      form_set_error('site_frontpage', t("The path '@path' is either invalid or you do not have access to it.", array('@path' => $item['link_path'])));
    }
  }
  
  /**
   * If on the homepage, set $_GET['q'] to the appropriate value.
   */
  function execute() {
    if ($_SERVER['REQUEST_URI'] != base_path()) {
      // Do nothing as we're not on the front page of the site.
      return;
    }

    $contexts = context_active_contexts();
    foreach ($contexts as $name => $context) {
      if ($frontpage = $context->reactions[$this->plugin]['site_frontpage']) {
        $_GET['q'] = drupal_get_normal_path($frontpage);
      }
    }
  }
}
