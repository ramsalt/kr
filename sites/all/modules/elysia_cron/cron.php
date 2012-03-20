<?php
// $Id: cron.php,v 1.2.2.1 2009/06/24 14:32:00 gotheric Exp $

/**
 * @file
 * Handles incoming requests to fire off regularly-scheduled tasks (cron jobs).
 */

if (!file_exists('includes/bootstrap.inc') && preg_match('@^(.*)[\\\\/]sites[\\\\/][^\\\\/]+[\\\\/]modules[\\\\/]elysia(_cron)?$@', getcwd(), $r))
  chdir($r[1]);

include_once './includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
if (function_exists('elysia_cron_run'))
  elysia_cron_run();
else
  drupal_cron_run();
