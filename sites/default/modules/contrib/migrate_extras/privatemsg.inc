<?php
// $Id: privatemsg.migrate.inc,v 1.1 2010/01/19 19:41:18 textplease Exp $

/**
 * @file
 * Support for the Privatemsg module.
 */

/**
 * Destination class implementing
 */
class MigrateDestinationPrivatemsg extends MigrateDestination {
  static public function getKeySchema() {
    return array(
      'id' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'description' => 'ID of private message',
      ),
    );
  }

  /**
   * Basic initialization
   */
  public function __construct($language = NULL, $text_format = NULL) {
    parent::__construct('privatemsg', 'privatemsg', $language, $text_format);
  }

  /**
   * Returns a list of fields available to be mapped for private messages
   *
   * @return array
   *  Keys: machine names of the fields (to be passed to addFieldMapping)
   *  Values: Human-friendly descriptions of the fields.
   */
  public function fields() {
    $fields = array(
      'mid' => t('Message ID'), //this is to be set on the fly, don't need
      'author' => t('Author UID'), // sender of msg
      'subject' => t('Subject'), // subject
      'body' => t('Message Body'), // the actual message
      'format' => t('Message Input format ID'), //the input format ID
      'timestamp' => t('Timestamp'), //timestamp

      //'thread_id' => t('Thread Message ID'), //mid of original msg ro threaded discussion (optional)
      'recipient' => t('UID of the recipient'),
      'author_is_new' => t('Whether the author has read this message'),
      'recipient_is_new' => t('Whether the recipient has read this message'),
      'author_del' => t('Whether the author has deleted this message'),
      'recipient_del' => t('Whether the recipient has deleted this message'),
    );

    $fields += migrate_handler_invoke_all('Privatemsg', 'fields', $this->entityType, $this->bundle);

    return $fields;
  }


  function _privatemsg_migrate_save($message) {

    // @TODO: We should probably be running this here. Though $message is in
    // the wrong format to do it and I'm not sure what other implications it
    // will have. Same goes for the privatemsg_message_insert() hook at the
    // end of this function.
    // drupal_alter('privatemsg_message_presave', $message);

    // Save the message body.
    db_query("INSERT INTO {pm_message} (subject, author, body, format, timestamp) VALUES ('%s', %d, '%s', %d, %d)", $message->subject, $message->author, $message->body, $message->format, $message->timestamp);
    $mid = db_last_insert_id('pm_message', 'mid');
    $message->mid = $mid;

    // Save message to recipients.
    // @TODO: If we want to support importing of threaded messages, then this
    // needs some work.
    // Set the thread to match the message
    $message->thread_id = $mid;
    $index_sql = "INSERT INTO {pm_index} (mid, thread_id, uid, is_new, deleted) VALUES (%d, %d, %d, %d, %d)";
    db_query($index_sql, $mid, $message->thread_id, $message->recipient, $message->recipient_is_new, $message->recipient_del);

    // Also add a record for the author to the pm_index table.
    db_query($index_sql, $mid, $message->thread_id, $message->author, $message->author_is_new, $message->recipient_del);

    // module_invoke_all('privatemsg_message_insert', $message);

    // Assuming success
    $message->success = TRUE;
    return $message;
  }

  /**
   * Import a single private message.
   *
   * @param $message
   *  Message object to build.
   * @param $row
   *  Raw source data object
   * @return array
   *  Array of key fields (mid only in this case) of the message that was
   *  saved if successful. FALSE on failure.
   */
  public function import(stdClass $message, stdClass $row) {
    $migration = Migration::currentMigration();

    // Updating previously-migrated content?
    if (isset($row->migrate_map_destid1)) {
      $message->mid = $row->migrate_map_destid1;
    }
    if ($migration->getSystemOfRecord() == Migration::DESTINATION) {
      if (!isset($message->mid)) {
        throw new MigrateException(t('System-of-record is DESTINATION, but no destination uid provided'));
      }
    }

    //$this->prepare($message, $row);
    //$new_thread = $message->new_thread;
    migrate_instrument_start('privatemsg_save');
    $newmessage = $this->_privatemsg_migrate_save($message);
    migrate_instrument_stop('privatemsg_save');

    if ($newmessage->success) {
      //$this->complete($newmessage, $row);
      $return = isset($newmessage->mid) ? array($newmessage->mid) : FALSE;
    }
    else {
      $return = FALSE;
    }

    return $return;
  }

  /*
  public function prepare($message, stdClass $row) {
    // We can't just pass the $msg object into privatemsg_new_thread() as is,
    // so lets fix it up.

    // Get full user objects for author and recipients, seems like a lot of
    // overhead?
    //$author = user_load(array('uid' => $message->author));
    //$recipient = user_load(array('uid' => $message->recipient));
    //$new_thread->recipients = array($recipient);

    // Set options
    //$options['author'] = $author;
    $options['timestamp'] = $message->timestamp;
    $options['format'] = $message->format;
    $new_thread->options = $options;
    $new_thread->message = $message->body;
    $new_thread->subject = $message->subject;

    //add new items to msg (while keeping the old for later)
    //$message->new_thread = $new_thread;

    // Then call any prepare handler for this specific Migration.
    if (method_exists($migration, 'prepare')) {
      $migration->prepare($entity, $source_row);
    }
  }
  */

  /*
  public function complete($message, stdClass $source_row) {
    $migration = Migration::currentMigration();

    foreach ($migration->sourceKeyMap() as $field_name => $key_name)  {
      $keys[$key_name] = $source_row->$field_name;
    }

    if ($message->message['mid']) {
      if ($message->deleted) {
        //delete the author record
        privatemsg_message_change_delete($message->message['mid'], 1, $message->message['author']);
      }

      if (!$msg->is_new) {
        privatemsg_thread_change_status($message->message['mid'], PRIVATEMSG_READ, $message->message['recipients'][0]);
      }
    }

    // Then call any complete handler for this specific Migration.
    if (method_exists($migration, 'complete')) {
      $migration->complete($message, $source_row);
    }
  }
  */

  public function rollback(array $key) {
    $mid = reset($key);

    migrate_instrument_start('private_message_sql_delete');
    db_query("DELETE FROM {pm_index} WHERE mid = %d", $mid);
    db_query("DELETE FROM {pm_message} WHERE mid = %d", $mid);
    migrate_instrument_stop('private_message_sql_delete');
    return TRUE;
  }
}
