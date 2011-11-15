
-- SUMMARY --

Poll Enhancements module enables anonymous users to vote on polls without IP address restrictions.

For a full description of the module, visit the project page:
  http://drupal.org/project/pollanon

To submit bug reports and feature suggestions, or to track changes:
  http://drupal.org/project/issues/pollanon


-- REQUIREMENTS --

Poll module enabled. For more information, visit the handbook page:
  http://drupal.org/handbook/modules/poll


-- INSTALLATION --

* Install as usual, see http://drupal.org/node/70151 for further information.


-- CONFIGURATION --

* Customize the module settings in Administer >> Site configuration >> Poll Enhancements.


-- VARNISH --

* Varnish users should make adjustments to their VCL configurations to ignore pollanon cookies.
  Do one of the following modifications:

  A) Ignore all other except session cookies:
      sub vcl_recv {
        if (req.http.Cookie !~ ";\s*(SESS[a-z0-9]+)=") {
          unset req.http.Cookie;
        }
      }

  B) Specify cookies to be ignored:
      sub vcl_recv {
        // Remove has_js and Google Analytics __* cookies.
        set req.http.Cookie = regsuball(req.http.Cookie, "(^|;\s*)(__[a-z]+|has_js)=[^;]*", "");
        // Remove pollanon cookies.
        set req.http.Cookie = regsuball(req.http.Cookie, "(^|;\s*)(pa-(.*))=[^;]*", "");
        // Remove a ";" prefix, if present.
        set req.http.Cookie = regsub(req.http.Cookie, "^;\s*", "");
        // Remove empty cookies.
        if (req.http.Cookie ~ "^\s*$") {
          unset req.http.Cookie;
        }
      }


-- CONTACT --

Current maintainers:
* Tomi Mikola (TomiMikola) - http://drupal.org/user/183191


This project has been sponsored by:
* Aller Media
    Aller is a magazine publisher in the Nordic countries,
    and has several brand-related web sites.
    Aller Media puts a strong emphasis on digital media.
    Visit http://www.aller.fi/en/ for more information.

* Mearra
    Professional Drupal consulting in Europe.
    Visit http://mearra.com for more information.
