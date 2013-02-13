<?php
?>
<div id="embedded-node-<?php print $node->nid; ?>" class="embedded-node 
  <?php if (!$node->status) { print ' node-unpublished'; } ?>  embedded-node-type-<?php print $node->type; ?>">
  <div class="embedded-node">
    <div class="content clear-block">
      <?php print $node->body ?>
    </div>
  </div>
</div>
