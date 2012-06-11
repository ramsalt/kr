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
?>
<!--



Hei, du, HTML-kildekodeleser! :-)

Denne nettsiden er laget ved hjelp av fri programvare. Rammeverket er Drupal.
PHP er programmeringsspråket og databasen er MySQL. Herligheten bruker Apache som webserver og Varnish som HTTP akselerator.

Har du noen spørsmål svarer vi gjerne på dem, bare kontakt oss på www.ramsalt.com

Ha en fin dag!



-->
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
     version="XHTML+RDFa 1.0" 
     xmlns:og="http://opengraphprotocol.org/schema/"
     >
<head>

  <title><?php print $head_title ?></title>
  <?php print $op_head; ?>
  <?php print $styles ?>
  <?php if ($is_front): ?>
      <meta http-equiv="refresh" content="600" />
      <meta property="fb:admins" content="637922720,100002054981502,1517137300,705756604,1566145296,686475782"/>
  <?php endif; ?>
  <!--[if gte IE 6]><?php print openpublish_get_ie_styles(); ?><![endif]-->  
  <!--[if gte IE 6]><link type="text/css" rel="stylesheet" media="all" href="<?php print base_path().drupal_get_path('theme', 'kr2011'); ?>/css/ie.css" ><![endif]-->
  <!--[if IE 6]><?php print openpublish_get_ie6_styles(); ?><![endif]-->
  <?php  /*<link href="http://cloud.webtype.com/css/7e0250ce-8821-4a64-958c-515d184ac628.css" rel="stylesheet" type="text/css" /> */ ?>
</head>

<body <?php print openpublish_body_classes($left, $right, $body_classes); ?> >
  <?php if (!empty($admin)) print $admin; ?>
  <div id="outer-wrapper"> 
  <div id="wrapper">    	
  <div id="header">
  
        <div id="toppannonser">

        <!-- Annonse 768x150 piksler øverst venstre  -->

        <div id="toppann_left">

            <?php print $top_left; ?> 
    	</div>

		<!--  Annonse 180x150 piksler øverst høyre  -->
        <div id="toppann_right">

		    <?php print $top_right; ?> 

        </div><!-- .toppann_right-->
      </div><!-- #toppannonser -->


  
  
  
    <?php print $header; ?>   
    <div class="clear"></div>
  </div> <!-- /#header -->
  
  <?php
  /*if (menu_tree('navigation')):  . $GLOBALS['user']->mail . '!'
   * <li class="hello"><?php print t('Logget inn som '). $GLOBALS['user']->mail . ' '; ?></li>
          
   */
    if (menu_tree('navigation')): ?>

    <div id="top-menu" class="clearfix">
    	
      <ul id="login-menu">
        <?php if (user_is_logged_in()) : ?>
          <?php if (!empty($GLOBALS['user']->ip_login_match)) : ?>
              <li><?php print l('Automatisk logget inn fra ' . $GLOBALS['user']->name, 'node/82938'); ?></li>
          <?php else : ?>
              <li><?php print l($GLOBALS['user']->mail, 'user/' . $GLOBALS['user']->uid . '/edit/Abonnementsinfo') ?></li>
              <li><?php print l(t('Logg ut'), 'logout'); ?></li>
          <?php endif; ?>
              
        <?php else : ?>
          <?php /*<li class="hello"><?php print t('Hei!'); ?></li>*/ ?>
          <li><?php print l(t('Logg inn'), 'user', array('html' => true, 'query' => drupal_get_destination())) ?> <?php print t('eller'); ?> <?php print l(t('registrer deg'),'user/register'); ?></li>
        <?php endif; ?>
      </ul>
		  
      <?php print menu_tree('menu-top-menu'); ?>
    </div>
  <?php endif; ?>		

  <div id="logo-area" class="clearfix">	    
    <div id="logo"><a href="<?php print check_url($front_page); ?>" title="<?php print check_plain($site_name); ?>"><img src="<?php print check_url($logo); ?>" alt="<?php print check_plain($site_name); ?>" /></a>
    </div><!--/ #logo -->
  <?php /*<div class="fagpresse">
      <img src="/sites/default/files/fagpressepris.jpg" width="42" height="90"alt="fagpressepris" />
      <h3>Vinner av Fagpresseprisen</h3>
      <span><a href="<?php print url('node/81011'); ?>" title="Kommunal Rapport vant fagpresseprisen">Norges beste fagblad!</a></span>
  </div>  */?>  
    <div id="search_box_top" class="clearfix">
      <?php /*if ($search_box): ?><?php print $search_box; ?><?php endif;*/ ?>

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
        </div></form>

    </div>

  </div><!-- #logo-area -->        

  <div id="nav" class="clearfix">
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
  <div class="clear"></div>	
  <div id="container" class="clearfix">
