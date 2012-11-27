<?php

/**
 * @file jcarousel-view.tpl.php
 * View template to display a list as a carousel.
 */
?>
<h3>Bildegalleri</h3>
<ul class="<?php print $jcarousel_classes; ?>">
  <?php foreach ($rows as $id => $row): ?>
    <li class="<?php print $classes[$id]; ?>"><?php print $row; ?></li>
  <?php endforeach; ?>
</ul>