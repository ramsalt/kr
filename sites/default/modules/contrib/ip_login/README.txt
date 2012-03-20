IP Login - Login to Drupal automatically via your IP address
By David Thomas - davidwhthomas@gmail.com
and Jim Kirkpatrick - bad.octopus@gmail.com
April 2011

*** ABOUT ***
This module allows users to login first automatically via their IP address, wildcard or range, instead of using a username / password.
The module uses the core 'Profile' module to lookup a user's IP address - FOR NOW!

*** NOTE April 2011 ***
This version is an early preview of the 2.x-DEV branch and will soon loose the reliance on the core Profile module and gain
better integration with other modules and Drupal 7.

All information below is out of date but still relevant.



*** HOW IT WORKS ***
When a user visits any Drupal page, IP Login checks that they're not logged in and that IP login hasn't run yet for this session.
If they are a new anon user, the module checks if a record exists for the user's IP address by looking up the profile_values field for the IP Address in $_SERVER['REMOTE_HOST']
If a matching IP address is found in profile_values, it logs them in as that user.
If not, normal username / password authentication is still always available as a second step.

*** HOW TO INSTALL ****

1. Create a user profile textfield to store the user's IP address. e.g: profile_ip. I recommend making it a private field, only available to admins.
2. Copy the module folder 'ip_login' to your module folder (e.g sites/all/modules/ )
3. Enable the module from Drupal admin -> modules
4. Go to the site config settings at admin/settings/iplogin and select the profile field that contains a user's IP address.
5. Done.

*** HOW TO TEST ***

You can test it by entering your IP address in your user profile. If you need to find your external IP address, try http://whatismyip.com
If it's working, you should be able to close the browser, open it, go to your site and see the 'Welcome %name, you're now logged into %sitename' message after IP Login has logged you in.

