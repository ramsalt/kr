=====
Block Class
http://drupal.org/project/block_class
-----
Block Class was developed and is maintained by Four Kitchens <http://fourkitchens.com>.


=====
Installation
-----

1. Enable the module.
2. Insert a PHP snippet to your theme's block.tpl.php file(s) that prints the $block_classes variable (see below).
3. To add a class to a block, simply visit that block's configuration page at Admin > Site Building > Blocks.


=====
Inserting the $block_classes variable into your theme.
-----
Add this snippet to your theme's block.tpl.php inside the block's class definition:

<?php print $block_classes; ?>

Here's the first line of the Garland theme's block.tpl.php prior to adding the code:

<div id="block-<?php print $block->module .'-'. $block->delta; ?>" class="clear-block block block-<?php print $block->module ?>">

And here's what the code should look like after adding the snippet:

<div id="block-<?php print $block->module .'-'. $block->delta; ?>" class="clear-block block block-<?php print $block->module ?> <?php print $block_classes; ?>">

IMPORTANT: Remember to separate the PHP snippet from the existing markup with a single space. If you don't add the space, your CSS classes could run together like this: "block-modulecustomclass" instead of "block-module customclass".
