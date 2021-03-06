<?php
// $Id: page.tpl.php,v 1.1.2.11 2010/10/20 18:32:12 tirdadc Exp $
 
 /**
  * @file page.tpl.php
  *
  * Main generic page template.
  * @ingroup page
  *
  * Available variables:
  *
  * General utility variables:
  * - $base_path: The base URL path of the Drupal installation. At the very
  *   least, this will always default to /.
  * - $css: An array of CSS files for the current page.
  * - $directory: The directory the theme is located in, e.g. themes/garland or
  *   themes/garland/minelli.
  * - $is_front: TRUE if the current page is the front page. Used to toggle the mission statement.
  * - $logged_in: TRUE if the user is registered and signed in.
  * - $is_admin: TRUE if the user has permission to access administration pages.
  *
  * Page metadata:
  * - $language: (object) The language the site is being displayed in.
  *   $language->language contains its textual representation.
  *   $language->dir contains the language direction. It will either be 'ltr' or 'rtl'.
  * - $head_title: A modified version of the page title, for use in the TITLE tag.
  * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
  *   so on).
  * - $styles: Style tags necessary to import all CSS files for the page.
  * - $scripts: Script tags necessary to load the JavaScript files and settings
  *   for the page.
  * - $body_classes: A set of CSS classes for the BODY tag. This contains flags
  *   indicating the current layout (multiple columns, single column), the current
  *   path, whether the user is logged in, and so on.
  *
  * Site identity:
  * - $front_page: The URL of the front page. Use this instead of $base_path,
  *   when linking to the front page. This includes the language domain or prefix.
  * - $logo: The path to the logo image, as defined in theme configuration.
  * - $site_name: The name of the site, empty when display has been disabled
  *   in theme settings.
  * - $site_slogan: The slogan of the site, empty when display has been disabled
  *   in theme settings.
  * - $mission: The text of the site mission, empty when display has been disabled
  *   in theme settings.
  *
  * Navigation:
  * - $search_box: HTML to display the search box, empty if search has been disabled.
  * - $primary_links (array): An array containing primary navigation links for the
  *   site, if they have been configured.
  * - $secondary_links (array): An array containing secondary navigation links for
  *   the site, if they have been configured.
  *
  * Page content (in order of occurrance in the default page.tpl.php):
  * - $left: The HTML for the left sidebar.
  *
  * - $breadcrumb: The breadcrumb trail for the current page.
  * - $title: The page title, for use in the actual HTML content.
  * - $help: Dynamic help text, mostly for admin pages.
  * - $messages: HTML for status and error messages. Should be displayed prominently.
  * - $tabs: Tabs linking to any sub-pages beneath the current page (e.g., the view
  *   and edit tabs when displaying a node).
  *
  * - $content: The main content of the current Drupal page.
  *
  * - $right: The HTML for the right sidebar.
  *
  * Footer/closing data:
  * - $feed_icons: A string of all feed icons for the current page.
  * - $footer_message: The footer message as defined in the admin settings.
  * - $footer : The footer region.
  * - $closure: Final closing markup from any modules that have altered the page.
  *   This variable should always be output last, after all other dynamic content.
  *
  * @see template_preprocess()
  * @see template_preprocess_page()
  * 
  *       	<div id="add-this" class="float-right clearfix">
          <?php print openpublish_addthis_widget($head_title); ?>
      	</div>
  */
 ?>

<?php print $page_header; ?>
<section>
  <?php if ($show_messages && $messages): ?>
  	<div id="msg" class="area frontpage">
  		<div class="wrapper">
			<div class="container container-16 clearfix">
  	  			<div class="inner-container clearfix">  	  		
	  	  			<div class="grid full nomargin">
  						<?php print $messages; ?>
  					</div>
  				</div>
  			</div>
  		</div>
  	</div>
  <?php endif; ?>	
  	  
  <div id="content-area" class="area frontpage">
  	<div class="wrapper">
	  <?php if($ad_right): ?>
  	  	<div id="ad-right" class="ad-right visible-desktop" style="left: 2000px;">
  	  		<?php print $ad_right; ?>
  	  	</div>
  	  <?php endif; ?>
  	  <div class="container container-16 clearfix">
  	  	<div class="inner-container clearfix">
  	  		
	  	  	<div class="grid full nomargin toplinje">
	  	  		<div class="one one_one">
	  	  			<div class="one-inner">
						<?php print $one_one; ?>
					</div>
				</div>
				<div class="one one_three">
					<div class="one-inner">
						<?php print $one_three; ?>
					</div>
				</div>				
				<div class="one one_two">
					<div class="one-inner">
						<?php print $one_two; ?>
					</div>
				</div>
			</div><!-- /.grid -->
			<div class="grid full nomargin deskbordertop">
				<div class="two">
					<div class="two-inner">
						<?php print $two; ?>
					</div>	
				</div>
			</div><!-- /.grid -->
			<div class="grid full nomargin threeart">
				<div class="three">
					<div class="three-inner">
						<?php print $three; ?>
					</div>	
				</div>
				<div class="three-art">
					<div class="three-art-inner">
						<?php print $three_art; ?>
					</div>	
				</div>
			</div><!-- /.grid -->
			<div class="grid full nomargin">
				<div class="four">
					<div class="four-inner">
						<?php print $four; ?>
					</div>	
				</div>
			</div><!-- /.grid -->
			<div class="grid full nomargin">
				<div class="five">
					<div class="five-inner">
						<?php print $five; ?>
					</div>	
				</div>
			</div><!-- /.grid -->
			<div class="grid full nomargin">
				<div class="six">
					<div class="six-inner">
						<?php print $six; ?>
					</div>	
				</div>
			</div><!-- /.grid -->
			<div class="grid full nomargin">
				<div class="seven_one_two">
					<div class="seven seven_one">
						<div class="seven-inner">
							<?php print $seven_one; ?>
						</div>	
					</div>
					<div class="seven seven_two">
						<div class="seven-inner">
							<?php print $seven_two; ?>
						</div>	
					</div>
				</div>
				<div class="seven seven_three">
					<div class="seven-inner">
						<?php print $seven_three; ?>
					</div>	
				</div>
			</div><!-- /.grid -->
			<div class="grid full nomargin">
				<div class="eight">
					<div class="eight-inner">
						<?php print $eight; ?>
					</div>	
				</div>
			</div><!-- /.grid -->		
			<div class="grid full nomargin">
				<div class="nine">
					<div class="nine-inner">
						<?php print $nine; ?>
					</div>	
				</div>
			</div><!-- /.grid -->		
			<div class="grid full nomargin">
				<div class="ten ten_one">
					<div class="ten-inner">
						<?php print $ten_one; ?>
					</div>	
				</div>
				<div class="ten ten_two">
					<div class="ten-inner">
						<?php print $ten_two; ?>
					</div>	
				</div>
				<div class="ten ten_three">
					<div class="ten-inner">
						<?php print $ten_three; ?>
					</div>	
				</div>								
			</div><!-- /.grid -->			
		</div> <!-- /.inner-container -->
	</div> <!-- /.container -->
  </div> <!-- /.wrapper -->
</div> <!-- /#content-area -->
</section>
<?php print $page_footer;
