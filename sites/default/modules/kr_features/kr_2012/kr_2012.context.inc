<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function kr_2012_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'kr2012-article';
  $context->description = 'Kr2012 node article';
  $context->tag = 'node';
  $context->conditions = array(
    'context_condition_theme' => array(
      'values' => array(
        'kr2012' => 'kr2012',
      ),
    ),
    'node' => array(
      'values' => array(
        'article' => 'article',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-also_read-block_1' => array(
          'module' => 'views',
          'delta' => 'also_read-block_1',
          'region' => 'right',
          'weight' => 0,
        ),
        'kr_most_viewed-0' => array(
          'module' => 'kr_most_viewed',
          'delta' => 0,
          'region' => 'right',
          'weight' => 1,
        ),
        'views-siste_saker-block_1' => array(
          'module' => 'views',
          'delta' => 'siste_saker-block_1',
          'region' => 'right',
          'weight' => 2,
        ),
        'views-bilde_slider_node-block_1' => array(
          'module' => 'views',
          'delta' => 'bilde_slider_node-block_1',
          'region' => 'over_content',
          'weight' => 0,
        ),
        'kr_diverse-1' => array(
          'module' => 'kr_diverse',
          'delta' => 1,
          'region' => 'over_content',
          'weight' => 1,
        ),
        'disqus-disqus_comments' => array(
          'module' => 'disqus',
          'delta' => 'disqus_comments',
          'region' => 'under_content',
          'weight' => 0,
        ),
      ),
      'layout' => 'default',
    ),
    'block_class' => array(
      'right' => array(
        'class' => '',
        'blocks' => array(
          'views-also_read-block_1' => array(
            'class' => 'listeboks',
          ),
          'kr_most_viewed-0' => array(
            'class' => 'listeboks',
          ),
          'views-siste_saker-block_1' => array(
            'class' => 'listeboks',
          ),
        ),
      ),
      'over_content' => array(
        'class' => '',
        'blocks' => array(
          'views-bilde_slider_node-block_1' => array(
            'class' => '',
          ),
          'kr_diverse-1' => array(
            'class' => '',
          ),
        ),
      ),
      'under_content' => array(
        'class' => '',
        'blocks' => array(
          'disqus-disqus_comments' => array(
            'class' => '',
          ),
        ),
      ),
      'header' => array(
        'class' => '',
      ),
      'footer' => array(
        'class' => '',
      ),
      'one_one' => array(
        'class' => '',
      ),
      'one_two' => array(
        'class' => '',
      ),
      'one_three' => array(
        'class' => '',
      ),
      'two' => array(
        'class' => '',
      ),
      'three' => array(
        'class' => '',
      ),
      'four' => array(
        'class' => '',
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Kr2012 node article');
  t('node');
  $export['kr2012-article'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'kr_kategori';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'context_condition_theme' => array(
      'values' => array(
        'kr2012' => 'kr2012',
      ),
    ),
    'views' => array(
      'values' => array(
        'taxonomy_term:page' => 'taxonomy_term:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'kr_most_viewed-0' => array(
          'module' => 'kr_most_viewed',
          'delta' => 0,
          'region' => 'right',
          'weight' => 0,
        ),
      ),
      'layout' => 'default',
    ),
    'block_class' => array(
      'right' => array(
        'class' => '',
        'blocks' => array(
          'kr_most_viewed-0' => array(
            'class' => 'listeboks',
          ),
        ),
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
      'toparea' => array(
        'class' => '',
      ),
      'one_one' => array(
        'class' => '',
      ),
      'one_two' => array(
        'class' => '',
      ),
      'one_three' => array(
        'class' => '',
      ),
      'two' => array(
        'class' => '',
      ),
      'three' => array(
        'class' => '',
      ),
      'four' => array(
        'class' => '',
      ),
      'five' => array(
        'class' => '',
      ),
      'six' => array(
        'class' => '',
      ),
      'seven_one' => array(
        'class' => '',
      ),
      'seven_two' => array(
        'class' => '',
      ),
      'seven_three' => array(
        'class' => '',
      ),
      'eight' => array(
        'class' => '',
      ),
      'nine' => array(
        'class' => '',
      ),
      'ten_one' => array(
        'class' => '',
      ),
      'ten_two' => array(
        'class' => '',
      ),
      'ten_three' => array(
        'class' => '',
      ),
    ),
  );
  $context->condition_mode = 1;
  $export['kr_kategori'] = $context;

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
        'openx-3' => array(
          'module' => 'openx',
          'delta' => 3,
          'region' => 'three',
          'weight' => 0,
        ),
        'views-forside-block_4' => array(
          'module' => 'views',
          'delta' => 'forside-block_4',
          'region' => 'four',
          'weight' => 0,
        ),
        'views-jobbmarkede-block_1' => array(
          'module' => 'views',
          'delta' => 'jobbmarkede-block_1',
          'region' => 'five',
          'weight' => 0,
        ),
        'views-forside-block_5' => array(
          'module' => 'views',
          'delta' => 'forside-block_5',
          'region' => 'six',
          'weight' => 0,
        ),
        'openx-1' => array(
          'module' => 'openx',
          'delta' => 1,
          'region' => 'seven_one',
          'weight' => 0,
        ),
        'views-forside-block_6' => array(
          'module' => 'views',
          'delta' => 'forside-block_6',
          'region' => 'seven_two',
          'weight' => 0,
        ),
        'views-economic_blogg-block_1' => array(
          'module' => 'views',
          'delta' => 'economic_blogg-block_1',
          'region' => 'seven_three',
          'weight' => 0,
        ),
        'views-lederspalten-block_1' => array(
          'module' => 'views',
          'delta' => 'lederspalten-block_1',
          'region' => 'seven_three',
          'weight' => 1,
        ),
        'views-lederlogg-block_1' => array(
          'module' => 'views',
          'delta' => 'lederlogg-block_1',
          'region' => 'seven_three',
          'weight' => 2,
        ),
        'views-Blogger-block_2' => array(
          'module' => 'views',
          'delta' => 'Blogger-block_2',
          'region' => 'seven_three',
          'weight' => 3,
        ),
        'views-forside-block_7' => array(
          'module' => 'views',
          'delta' => 'forside-block_7',
          'region' => 'eight',
          'weight' => 0,
        ),
        'views-scroll_bilder-bilde_scroller' => array(
          'module' => 'views',
          'delta' => 'scroll_bilder-bilde_scroller',
          'region' => 'nine',
          'weight' => 0,
        ),
        'views-kr_quizen-block_1' => array(
          'module' => 'views',
          'delta' => 'kr_quizen-block_1',
          'region' => 'ten_one',
          'weight' => 0,
        ),
        'kr_most_viewed-0' => array(
          'module' => 'kr_most_viewed',
          'delta' => 0,
          'region' => 'ten_two',
          'weight' => 0,
        ),
        'block-7' => array(
          'module' => 'block',
          'delta' => 7,
          'region' => 'ten_three',
          'weight' => 0,
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
      'toparea' => array(
        'class' => '',
      ),
      'ad_right' => array(
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
      'three' => array(
        'class' => '',
        'blocks' => array(
          'openx-3' => array(
            'class' => '',
          ),
        ),
      ),
      'four' => array(
        'class' => '',
        'blocks' => array(
          'views-forside-block_4' => array(
            'class' => '',
          ),
        ),
      ),
      'five' => array(
        'class' => '',
        'blocks' => array(
          'views-jobbmarkede-block_1' => array(
            'class' => '',
          ),
        ),
      ),
      'six' => array(
        'class' => '',
        'blocks' => array(
          'views-forside-block_5' => array(
            'class' => '',
          ),
        ),
      ),
      'seven_one' => array(
        'class' => '',
        'blocks' => array(
          'openx-1' => array(
            'class' => '',
          ),
        ),
      ),
      'seven_two' => array(
        'class' => '',
        'blocks' => array(
          'views-forside-block_6' => array(
            'class' => '',
          ),
        ),
      ),
      'seven_three' => array(
        'class' => '',
        'blocks' => array(
          'views-economic_blogg-block_1' => array(
            'class' => 'rammeboks eco',
          ),
          'views-lederspalten-block_1' => array(
            'class' => 'rammeboks red leder',
          ),
          'views-lederlogg-block_1' => array(
            'class' => 'rammeboks red leder',
          ),
          'views-Blogger-block_2' => array(
            'class' => 'rammeboks blogger',
          ),
        ),
      ),
      'eight' => array(
        'class' => '',
        'blocks' => array(
          'views-forside-block_7' => array(
            'class' => '',
          ),
        ),
      ),
      'nine' => array(
        'class' => '',
        'blocks' => array(
          'views-scroll_bilder-bilde_scroller' => array(
            'class' => '',
          ),
        ),
      ),
      'ten_one' => array(
        'class' => '',
        'blocks' => array(
          'views-kr_quizen-block_1' => array(
            'class' => 'rammeboks red quiz',
          ),
        ),
      ),
      'ten_two' => array(
        'class' => '',
        'blocks' => array(
          'kr_most_viewed-0' => array(
            'class' => 'rammeboks red',
          ),
        ),
      ),
      'ten_three' => array(
        'class' => '',
        'blocks' => array(
          'block-7' => array(
            'class' => 'rammeboks red',
          ),
        ),
      ),
    ),
  );
  $context->condition_mode = 1;
  $export['ny_forside'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ny_global';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'context_condition_theme' => array(
      'values' => array(
        'kr2012' => 'kr2012',
      ),
    ),
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'kr_diverse-2' => array(
          'module' => 'kr_diverse',
          'delta' => 2,
          'region' => 'prearea',
          'weight' => 0,
        ),
        'openx-2' => array(
          'module' => 'openx',
          'delta' => 2,
          'region' => 'ad_right',
          'weight' => 0,
        ),
        'openx-6' => array(
          'module' => 'openx',
          'delta' => 6,
          'region' => 'ad_right',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;
  $export['ny_global'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ny_sitewide';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'context_condition_theme' => array(
      'values' => array(
        'kr2012' => 'kr2012',
      ),
    ),
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'openx-8' => array(
          'module' => 'openx',
          'delta' => 8,
          'region' => 'toparea',
          'weight' => 0,
        ),
        'openx-7' => array(
          'module' => 'openx',
          'delta' => 7,
          'region' => 'toparea',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;
  $export['ny_sitewide'] = $context;

  return $export;
}
