<?php
// $Id: simplenews-newsletter-body.tpl.php,v 1.1.2.4 2009/01/02 11:59:33 sutharsan Exp $

/**
 * @file
 * Default theme implementation to format the simplenews newsletter body.
 *
 * Copy this file in your theme directory to create a custom themed body.
 * Rename it to simplenews-newsletter-body--<tid>.tpl.php to override it for a
 * newsletter using the newsletter term's id.
 *
 * Available variables:
 * - node: Newsletter node object
 * - $body: Newsletter body (formatted as plain text or HTML)
 * - $title: Node title
 * - $language: Language object
 *
 * @see template_preprocess_simplenews_newsletter_body()
 */


/* Bilder
<img src="/<?php print path_to_theme();?>/gruppen.gif" width="130" height="55" alt="" border="0" />
*/


/* The following should be moved to template_preprocess_simplenews_newsletter_body() when
we can use our own template. I don't want to mess with Rubik theme.
We need to do som nasty hacks to rewrite HTML code */

/* Add font style to the title */
//$body = str_replace('<h2>', '<h2 style="font-size:21px;margin:0 0 10px;font-family:Helvetica, sans-serif">', $body);

/* Add font style to content enteties */

$view = views_get_view('jobs');
$display = $view->execute_display('block_2');
$tofind = array('class="date-display-single"', 'class="views-field-field-arbeidsgiver-value"', 'a href=');
$toreplace = array('style="color: #5C5C5C;font-family: Helvetica,sans-serif; font-size: 12px;line-height: 1.4;padding-bottom:.5em;display:block"',
    'style="color: #5C5C5C;font-family: Helvetica,sans-serif; font-size: 12px;line-height: 1.4;"',
    'a style="color:#0a2339;font-weight:700;font-size:14px;text-decoration:none;font-family:Helvetica, sans-serif" href='
);
$display['content'] = str_replace($tofind,$toreplace, $display['content']);


?>
<HTML><HEAD><META http-equiv="Content-Type" content="text/html; charset=ISO-8859-1"><meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<title>Kommunal Rapport - nyhetsbrev</title></HEAD><BODY  style="margin:0;padding:0;" text="black"><STYLE type=text/css>
A {
  COLOR: #ae0909;
  TEXT-DECORATION: underline;
}
IMG {border:2px solid black}

</STYLE>

    <table cellspacing="0" cellpadding="0" align="center" style="width:790px;margin:30px auto;vertical-align:top">
      <tbody>
        <tr>

          <td style="margin:0;padding:25px;background: none repeat scroll 0 0 #003762;" colspan="2">
            <a href="http://kommunal-rapport.no/">
            <img alt="" src="http://www.kommunal-rapport.no/sites/default/files/kr2011_logo.png" width="469" height="54">
            </a>
          </td>
        </tr>
        <tr>
          <td align="left" valign="top" style="border:1px solid #cfcfcf;vertical-align:top">
            <table style="width:595px;margin:0">
              <tbody>
                <tr>

                  <td style="padding:10px 3px">
                    <table>
                      <tbody>
                        <tr>
                          <td colspan="2">

                            <?php print $body; ?>
                          <?php /*
                            <h2 style="font-size:21px;margin:0 0 10px;font-family:Helvetica, sans-serif">
                              Frp: â€“ En skam at barnetrygden ikke ÃƒÂ¸kes
                            </h2>
                            <p style="color:#959595;font-size:12px;margin:0 0 10px;padding:0;font-family:Helvetica, sans-serif">

                              (03.05.2011)
                            </p>
                            <p style="margin:0;padding:0">
                              <a target="_blank" style="color:#0a2339;font-weight:700;font-size:14px;text-decoration:none;font-family:Helvetica, sans-serif" href="http://www.kommunal-rapport.no/id/11206293.0">Les hele saken Ã‚Â»</a>
                            </p>

                            */ ?>
                          </td>
                        </tr>
                      </tbody>
                    </table>

                  </td>
                </tr>
              </tbody>
            </table>
          </td>
          <td align="right" valign="top" style="margin:0;padding:0 0 15px;vertical-align:top">
            <table cellspacing="0" cellpadding="0">
              <tbody>
                <tr>

                  <td style="padding:0 0 15px">
                    <table cellspacing="0" cellpadding="0" style="width:173px">
                      <tbody>
                        <tr>
                          <td style="padding:0 0 15px">
                            <table cellspacing="0" cellpadding="0" style="width:100%;border:1px solid #cfcfcf">
                              <tbody>
                                <tr>
                                  <td style="padding:1px">

                                    <h3 style="background:#003762;color:#fff;font-weight:700;text-transform:uppercase;font-size:13px;margin:0px;padding:3px;display:block;font-family:Helvetica, sans-serif">
                                      Ledige stillinger
                                    </h3>
                                  </td>
                                </tr>
                                <tr>
                                  <td style="padding:5px">

                                  <a href='http://openx.dev.ramsalt.com/delivery/ck.php?zoneid=15' target='_blank'><img src='http://openx.dev.ramsalt.com/delivery/avw.php?zoneid=15&amp;cb=INSERT_RANDOM_NUMBER_HERE' border='0' alt='' /></a>

                                <?php print $display['content']; ?>

                                  </td>
                                </tr>
                              </tbody>
                            </table>

                          </td>
                        </tr>
                      </tbody>
                    </table>
                  </td>
                </tr>
              </tbody>
            </table>
          </td>

        </tr>
        <tr>

