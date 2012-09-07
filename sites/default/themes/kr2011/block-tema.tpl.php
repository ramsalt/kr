<?php
// $Id: block.tpl.php,v 1.3 2007/08/07 08:39:36 goba Exp $
?>
<div id="block-<?php print $block->module .'-'. $block->delta; ?>" class="clear-block block block-<?php print $block->module ?> tema-layout-<?php print $block->layout ?>">

<?php if (!empty($block->subject)): ?>
  <div class="title"><a href="<?php print url('node/'.$block->node_id); ?>"><?php print $block->subject ?></a></div>
<?php endif;?>
  <div class="content"><?php print $block->content ?></div>
</div>
