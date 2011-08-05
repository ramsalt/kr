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

print '<h2>'.$form['#parameters'][2]->title.'</h2>';
print '<p>'.$form['#parameters'][2]->teaser.'</h2>';
print drupal_render($form);

?>

