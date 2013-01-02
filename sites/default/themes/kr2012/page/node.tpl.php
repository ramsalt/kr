<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?>">

  <?php print $picture ?>
  <div>	
  	<h1 property="dc:title"><?php print $title; ?></h1>
  </div>
  <?php if ($page == 0): ?>
    <h2><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
  <?php endif; ?>
  <?php if ($ingress): ?>
	<div class="ingress">
            <?php print $ingress_value; ?>
    </div><!-- /.ingress -->
  <?php endif; ?>
  <div class="byline"><?php print $byline; ?></div>

  <div class="node-content">
    <?php print $content ?>
  </div>

</div>
