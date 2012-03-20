This module is a greenhouse for Rules functionality – triggers, actions and
conditions that could be included in the Rules module, but probably should be
tested out and voted on first. Feel free to add your own ideas, opinions,
examples and feature requests!

INSTALLATION
============

The usual. Download, enable. You will need the Rules module. (Surprise!)


RULES BONUS: CCK
================

Conditions

* Field value is one of several: This condition checks if a field contains one
  of several provided values. This could theoretically be done with Rules core,
  but would require terrible nesting of and/or statements.
* Field has content: This condition utilizes the CCK field callbacks for
  determining if the field is empty or not. Useful for checking if a complex
  CCK field has content or not.

Actions

* Set a CCK field without validation: This gives you a plain old textfield to
  enter data into CCK fields. That means that you won't be limited to
  validations or form elements that the CCK widget provides. Please have a look
  at http://drupal.org/node/1144404 if you'd like this functionality in Rules
  core.
* Insert a value in a multiple-value field: This action adds a new value to a
  multiple-value field, if it wasn't already present.
* Remove a value from a multiple-value field: This action kind of does the
  opposite to the previously described action.
* Get a field value, bypassing Token: This action gets a field value, even if a
  node hasn't been saved to the database yet. This is basically only for the
  cases when you're working on the node presave event, which causes Token to
  provide outdated content.
* Copy multiple field content between nodes: This action copies the content of
  selected fields from one node to another (assuming the fields exist on the
  target node). There are options for skipping empty fields when copying, and to
  also copy node title.
* Copy entire field content between nodes: This takes the field content and
  copies it into another field. Unlike other actions to set field content, this
  works well with multiple-value fields as well (and it has no restrictions on
  which field types to work with).
* Send e-mail to all users in a user reference field: This action mimics the 
  'send e-mail to a user' action, but does it for all users listed in a user
  reference field. Note that bloated user reference fields causes bloated e-mail
  sendouts – with potential negative side effects of servers dying and also
  becoming blacklisted.
* Insert multiple values to a CCK field: Insert a whole bunch of values into a
  multiple-value CCK field. Optionally clear the field before setting new
  values. (Duplicate values are ignored.)
* Force a text field to an allowed value: This checks a (single-value) text
  field against the allowed values for the field. If it doesn't match, the value
  is removed. Optionally does white space-insensitive and case-insensitive
  comparison. Can be useful when importing content.
* Merge two multiple-value fields: This takes all the values in a multiple-value
  field and inserts them into another multiple-value field (possibly in another
  node). Only values not already present will be inserted. Only works for fields
  with single-value storage keys.

RULES BONUS: COMMENT
====================

Actions

* Change the comment owner: This action updates the comment owner to a selected
  user.


RULES BONUS: MISCELLANEOUS
==========================

Conditions

* Verify path argument: Provides the option to check an eqality condition on one
  part of the path.
* Check number of results from a view: This condition loads a view and checks
  the number of results – condition is passed if it is at least as many results
  as you set. You can pass on arguments to the view.

Actions

* Load path argument: Loads a selected part of the argument into a string.
* Get a string with current time: Creates a string object with the current time,
  in a custom format and with the acting user's time zone settings.
* Use Views to load a node: This action executes a view of your choice,
  including arguments you send to it, and loads the first node returned by the
  view as a new Rules object. (Note that you might first want to check that the
  view actually has any result using the condition above.)
* Get URL alias for an internal path: Gives you the URL alias for any internal
  path. Could be useful for adding additional URL aliases for node related
  paths.
* Set the active menu item: This action is A FIRST ATTEMPT at setting the active
  menu item using Rules. It sets the active menu item in the sense that the menu
  recognises it and show all children links, but it does not yet set the
  'active' class to the item in question. Requires the Menu position module.
* Get import nid for content: This action may be useful if you're using the
  Feeds module, and use import nodes for importing content. Given an imported
  node, this action will give you the node ID for the node used to import it.
  Requires the Feeds module, obviosly.
* Set node creation time: This sets the post time for a node to the current
  time, or optionally any given time expression.


RULES BONUS: NUMBERS
====================

Actions

* Generate a random number: This gives a random integer in a set interval. Some
  validation checks on the interval is still missing.
* Sum up numbers: This provides a sum of a list of numbers you write. Tokens are
  allowed.
* Multiply numbers: Much like the action above, but multiplies instead of adds.
* Build a sum from Views: Get a sum of all the values in selected
  fields/columns, in a selected view. Use to build dynamically updated sums, and
  store/display them any way you want.


RULES BONUS: USER
=================

Conditions

* Node author is an authenticated user: This condition checks that a node has a
  real user account as owner – i.e. is not written by an anonymous user.
* A string is valid user name: This checks whether a given string is an ok user
  name, optionally also checking if the name is still available.

Actions

* Load the acting user: Guess what this action does. :-)
* Load session ID for active user: Provides the session ID as a number object,
  as defined by the Session API module. (Session API module is required.)
* Generate a valid user name: This action takes a string and processes it until
  it is a valid and unique Drupal user name. NOTE: It currently replaces invalid
  suggested strings with 'dummy name' instead of removing disallowed characters.
