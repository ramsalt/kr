<?php

/**
 * Handler for field of type list.
 */
class term_fields_handler_field_list extends term_fields_handler_field {
  
  /**
   * Render whatever the data is as a link to the term.
   *
   * Data should be made XSS safe prior to calling this function.
   */
  function render_link($data, $values) {
    if (!empty($this->options['link_to_term']) && $data !== NULL && $data !== '') {
      return l($data, 'taxonomy/term/' . $values->{$this->aliases['tid']}, array('html' => TRUE));
    }
    else {
      return $data;
    }
  }

  function render($values) {
    $options = isset($this->term_fields_field->options['options']) ? $this->term_fields_field->options['options'] : array();
    
    if (! array_key_exists($values->{$this->field_alias}, $options)) {
      return '';
    }
    
    return $this->render_link(check_plain($options[$values->{$this->field_alias}]), $values);
  }
}