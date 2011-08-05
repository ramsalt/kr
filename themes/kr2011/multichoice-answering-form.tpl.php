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

if(strlen($form['#parameters'][2]->title>2)){
  print '<h2>'.$form['#parameters'][2]->title.'</h2>';
}
if(strlen($form['#parameters'][2]->teaser>2)){
  print '<p>'.$form['#parameters'][2]->teaser.'</h2>';
}
print drupal_render($form);

?>

