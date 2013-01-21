<?php
// $Id: page-header.tpl.php,v 1.1.2.15 2010/12/01 18:00:38 tirdadc Exp $
/**
 * @file page-header.tpl.php
 * Header template.
 *
 * For the list of available variables, please see: page.tpl.php
 *
 * @ingroup page
 */
 global $user;

?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN" "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd">
<html 
     xmlns="http://www.w3.org/1999/xhtml"      
     xmlns:dc="http://purl.org/dc/terms/" 
     xmlns:dcmitype="http://purl.org/dc/terms/DCMIType/"
     xmlns:ctag="http://commontag.org/ns#"
     xmlns:foaf="http://xmlns.com/foaf/0.1/"      
     xmlns:v="http://rdf.data-vocabulary.org/#"
     xmlns:fb="http://www.facebook.com/2008/fbml"
     lang="<?php print $language->language; ?>" 
     dir="<?php print $language->dir; ?>"
     version="XHTML+RDFa 1.0" >
<head>
  <title><?php print str_replace('&amp;','', str_replace('&#173;', '', $head_title)) ?></title>
  <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, minimum-scale=1, user-scalable=no">
  <meta property="fb:admins" content="637922720,100002054981502,1517137300,705756604,1566145296,686475782"/>
  <?php if($node->type != 'webform'): ?>
  <meta http-equiv="refresh" content="600" >
  <?php endif; ?>
  <link href='/sites/default/themes/kr2012/css/font.css' rel='stylesheet' type='text/css'>
  <!-- <link href='http://fonts.googleapis.com/css?family=Merriweather' rel='stylesheet' type='text/css'> -->
  <?php print $op_head; ?>
  <?php print $styles ?>
  <?php print $scripts ?>
  <!--[if gte IE 6]><?php print openpublish_get_ie_styles(); ?><![endif]-->  
  <!--[if IE 6]><?php print openpublish_get_ie6_styles(); ?><![endif]-->
</head>

<body <?php print openpublish_body_classes($left, $right, $body_classes); ?> >
  <?php if (!empty($admin)) print $admin; ?>
  <a name="top"></a>
  <div id="outer-wrapper"> 
  <div id="wrapper">    	
  <header>  
  <div id="top-area" class="area">
  	<div class="wrapper">
  		<div class="container container-16 clearfix">
  			<div class="inner-container">
	  			<div class="grid grid-16">
	  				<div class="inner">
	  					<?php print $toparea; ?>
		  			</div>
	  			</div>
  			</div>
  		</div>
  	</div>
  </div>
  <div id="logo-area" class="area">
  	<div class="wrapper">
  		<div class="inner-wrapper">
	  		<div class="container container-16 clearfix">
	  			<div class="inner-container">
		  			<div class="grid grid-16">
		  				<div class="inner">
		    				<div id="logo"><a href="<?php print check_url($front_page); ?>" title="<?php print check_plain($site_name); ?>"><span><?php print check_plain($site_name); ?></span></a></div><!--/ #logo -->
		    					<div class="logo-item-wrapper">
				    				<div class="login-wrapper">
				    					<?php if($user->uid == 0){
				    						print '<a href="/user"><span>Logg inn</span></a>';	
				    					}else{
				    						print '<a href="/logout"><span>Logg ut</span></a>';
				    					}
				    					?>
				    					
				    				</div>
				    				<div class="search-wrapper">
				    					
				    					<?php
$block = module_invoke('search', 'block', 'view', 0);
print $block['content'];
?>				    				
										<?php /* print drupal_get_form('search_form'); */ ?>
									</div>
								</div>
		    			</div>
		    		</div>
		    	</div>
	    	</div>
    	</div>
    </div>
  </div><!-- #logo-area -->
  <div id="login-area" class="area">
  	<div class="wrapper">
  		<div class="inner-wrapper">
			<div class="container container-16 clearfix">
				<div class="inner-container">
		  			<div class="grid grid-16">
		  				<div class="inner">
							<div id="nav-button" class="visible-mobile navbuttun"><a href="">Meny</a></div>
							<?php if($user->uid == 0){
								print '<div id="login-content" class="visible-mobile navbuttun middle"><a href="/user">Logg inn</a></div>';
							}else{
								print '<div id="logout-content" class="visible-mobile navbuttun middle"><a href="/logout">Logg ut</a></div>';
							} ?>		  				
			  				<div id="search-content" class="visible-mobile navbuttun"><a href="/search/apachesolr_search"><span class="text">Søk</span><span class="icon"></span></a></div>
						  	<div id="nav">
							    <?php if (isset($expanded_primary_links)): ?>
							      <?php print theme('openpublish_menu', $expanded_primary_links); ?>
							    <?php else: ?> 
							      <?php if (isset($primary_links)) : ?>
							        <?php print theme('links', $primary_links, array('class' => 'links primary-links')) ?>
							      <?php endif; ?>
							      <?php if (isset($secondary_links)) : ?>
							        <?php print theme('links', $secondary_links, array('class' => 'links secondary-links')) ?>
							      <?php endif; ?>
							    <?php endif; ?>      
							</div> <!-- /#nav -->
							<div id="search-mob" class="mobhead">
								<div class="inner">
							        <form id="views-exposed-form-search-sorted-by-time-page-1" method="get" accept-charset="UTF-8" action="/sok">
								        <div><div class="view-search-sorted-by-time views-exposed-form">
								          <div class="views-exposed-widgets clear-block">
								                  <div class="views-exposed-widget">
								                                <div class="views-widget">
								                  <div id="edit-keys-wrapper" class="form-item">
								         <input type="text" class="form-text" title="Skriv inn ønskede søkekriterier." value="" size="15" id="edit-keys" name="keys" maxlength="128" />
								        </div>
								                </div>
								              </div>
								                <div class="views-exposed-widget">
								              <input type="submit" class="form-submit" value="Søk" id="edit-submit-search-sorted-by-time" />
								            </div>
								          </div>
								        </div>
								        </div>
							        </form>
								</div>
							</div><!-- /#search-mob -->
							<div id="user-login-mob" class="mobhead">
								<div class="inner">
									<?php global $user;
									if($user->uid == 0){
										print drupal_get_form('user_login');
									}  
									?>
								</div>
							</div>
			  			</div>
		  			</div>
				</div>
			</div>
  		</div>
  	</div>
  </div><! -- #login-area -->
  <?php if($prearea): ?>
    <div id="pre-area" class="area">
	  	<div class="wrapper">
	  		<div class="container container-16 clearfix">
	  			<div class="inner-container">
	  	  			<div class="grid pre full">
	  	  				<?php print $prearea; ?>
	  	  			</div>  				
	  			</div>
	  		</div>
	  	</div>
  	</div><!-- #pre-area -->
  <?php endif; ?> 
  </header>
