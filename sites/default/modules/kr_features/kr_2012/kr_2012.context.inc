<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function kr_2012_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ny_forside';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'context_condition_theme' => array(
      'values' => array(
        'kr2012' => 'kr2012',
      ),
    ),
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-forside-block_1' => array(
          'module' => 'views',
          'delta' => 'forside-block_1',
          'region' => 'one_one',
          'weight' => 0,
        ),
        'views-forside-block_2' => array(
          'module' => 'views',
          'delta' => 'forside-block_2',
          'region' => 'one_one',
          'weight' => 1,
        ),
        'views-forside-block_3' => array(
          'module' => 'views',
          'delta' => 'forside-block_3',
          'region' => 'one_two',
          'weight' => 0,
        ),
        'views-Kommentarutdrag-block_1' => array(
          'module' => 'views',
          'delta' => 'Kommentarutdrag-block_1',
          'region' => 'one_three',
          'weight' => 0,
        ),
        'boxes-box-4bb00d6c' => array(
          'module' => 'boxes',
          'delta' => 'box-4bb00d6c',
          'region' => 'one_three',
          'weight' => 1,
        ),
        'simplenews-22' => array(
          'module' => 'simplenews',
          'delta' => 22,
          'region' => 'one_three',
          'weight' => 2,
        ),
        'kr_2012-0' => array(
          'module' => 'kr_2012',
          'delta' => 0,
          'region' => 'two',
          'weight' => 0,
        ),
        'kr_2012-1' => array(
          'module' => 'kr_2012',
          'delta' => 1,
          'region' => 'two',
          'weight' => 1,
        ),
        'kr_2012-2' => array(
          'module' => 'kr_2012',
          'delta' => 2,
          'region' => 'two',
          'weight' => 2,
        ),
      ),
      'layout' => 'columns',
    ),
    'block_class' => array(
      'right' => array(
        'class' => '',
      ),
      'over_content' => array(
        'class' => '',
      ),
      'under_content' => array(
        'class' => '',
      ),
      'header' => array(
        'class' => '',
      ),
      'footer' => array(
        'class' => '',
      ),
      'one_one' => array(
        'class' => '',
        'blocks' => array(
          'views-forside-block_1' => array(
            'class' => '',
          ),
          'views-forside-block_2' => array(
            'class' => '',
          ),
        ),
      ),
      'one_two' => array(
        'class' => '',
        'blocks' => array(
          'views-forside-block_3' => array(
            'class' => '',
          ),
        ),
      ),
      'one_three' => array(
        'class' => '',
        'blocks' => array(
          'views-Kommentarutdrag-block_1' => array(
            'class' => 'rammeboks',
          ),
          'boxes-box-4bb00d6c' => array(
            'class' => 'rammeboks',
          ),
          'simplenews-22' => array(
            'class' => 'rammeboks',
          ),
        ),
      ),
      'two' => array(
        'class' => '',
        'blocks' => array(
          'kr_2012-0' => array(
            'class' => 'ownsection',
          ),
          'kr_2012-1' => array(
            'class' => 'ownsection',
          ),
          'kr_2012-2' => array(
            'class' => 'ownsection',
          ),
        ),
      ),
    ),
  );
  $context->condition_mode = 1;
  $export['ny_forside'] = $context;

  return $export;
}
