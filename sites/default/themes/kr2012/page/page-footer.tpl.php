<?php
// $Id: page-footer.tpl.php,v 1.1.2.2 2010/07/22 22:01:38 tirdadc Exp $
/**
 * @file page-footer.tpl.php
 * Footer template.
 *
 * For the list of available variables, please see: page.tpl.php
 *
 * @ingroup page
 */
?>
    </div> <!-- /#wrapper -->
  </div> <!-- /#outer-wrapper -->
        <div class="clear"></div>	
        <div id="footer-wrapper" class="clearfix">
        	<div id="footer">
        		<div id="footer-inner">
        			<div class="container container-16">
        				<div class="grid-16">
          					<?php print $footer_message . $footer ?>
          				</div>
          			</div>
          		</div>
          </div><!-- /#footer -->          
        </div> 
  
  <!-- /layout -->
  <?php print $closure ?>
</body>
</html>
