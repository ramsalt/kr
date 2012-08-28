<?php
/**
 * @file
 * Handles the layout of the multichoice answering form.
 *
 *
 * Variables available:
 * - $form
 */
//print '<pre>';print_r($form);print '</pre>';

if(strlen($variables['form']['question']['#value'])==0){
  print $form['#parameters'][2]->teaser;
}

print drupal_render($form);

?>

