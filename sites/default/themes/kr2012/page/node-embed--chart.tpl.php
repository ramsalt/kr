<?php
?>
<div id="embedded-node-<?php print $embedded_node->nid; ?>" class="embedded-node 
  <?php if (!$embedded_node->status) { print ' node-unpublished'; } ?>">
  
 

  <div class="content clear-block embedchartblock">
  	<div class="embedded-chart"><?php print $node->content['chart_output']['#value'] ?></div>
    <div class="embedded-text">
    <div class="embedded-title"><strong><?php print $title ?></strong></div> <div class="embedded-description"><?php print $node->field_description[0]['value'] ?></div>
    </div>
  </div>
  
</div>
