<?php

/**
 * Argument that refers to a certain book page.
 *
 * @ingroup views_argument_handlers
 */
class views_handler_argument_draggableviews_book extends views_handler_argument {
  function query() {
    $this->ensure_my_table();
    $mlid = db_result(db_query("SELECT mlid FROM {book} WHERE nid = %d", $this->argument));
    if (empty($mlid)) {
      // If argument doesn't refer to a menu entry force the view to be empty.
      $this->query->add_where(0, "0");
    }
    else {
      $depth = db_result(db_query("SELECT depth FROM {menu_links} WHERE mlid = %d", $mlid));
      $this->query->add_where(0, "$this->table_alias.p$depth = %d", $mlid);
      $this->query->add_where(0, "$this->table_alias.mlid <> %d", $mlid);
    }
  }
}
