<?php
/**
 * @file views-view-list.tpl.php
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 */

?>
<div class="item-list">
  <?php if (!empty($title)) : ?>
    <h3><?php print $title; ?></h3>
  <?php endif; ?>
  <div class="pretext"><?php print $view->display['default']->display_options['header']['text']['content']; ?></div>
  <<?php print $options['type']; ?>>
    <?php foreach ($rows as $id => $row): ?>
      <li class="<?php print $classes[$id]; ?>"><?php print $row; ?></li>
    <?php endforeach; ?>
  </<?php print $options['type']; ?>>
</div>