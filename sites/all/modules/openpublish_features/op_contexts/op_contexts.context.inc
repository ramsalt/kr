<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function op_contexts_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openpublish-general-sitewide';
  $context->description = '';
  $context->tag = 'OpenPublish General';
  $context->conditions = array(
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
          'delta' => '8',
          'region' => 'top_left',
          'weight' => 0,
        ),
        'openx-7' => array(
          'module' => 'openx',
          'delta' => '7',
          'region' => 'top_right',
          'weight' => 0,
        ),
        'openx-5' => array(
          'module' => 'openx',
          'delta' => '5',
          'region' => 'left',
          'weight' => 0,
        ),
        'openx-2' => array(
          'module' => 'openx',
          'delta' => '2',
          'region' => 'right',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('OpenPublish General');
  $export['openpublish-general-sitewide'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openpublish-listing_pages-articles';
  $context->description = '';
  $context->tag = 'OpenPublish Listing Page';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'articles' => 'articles',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-3' => array(
          'module' => 'block',
          'delta' => 3,
          'region' => 'right',
          'weight' => 0,
        ),
        'views-most_viewed_by_taxonomy-block' => array(
          'module' => 'views',
          'delta' => 'most_viewed_by_taxonomy-block',
          'region' => 'right',
          'weight' => 1,
        ),
        'views-most_commented_articles-block_1' => array(
          'module' => 'views',
          'delta' => 'most_commented_articles-block_1',
          'region' => 'right',
          'weight' => 2,
        ),
        'openx-2' => array(
          'module' => 'openx',
          'delta' => 2,
          'region' => 'over_content',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('OpenPublish Listing Page');
  $export['openpublish-listing_pages-articles'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openpublish-listing_pages-frontpage';
  $context->description = '';
  $context->tag = 'OpenPublish Listing Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-articles-block_2' => array(
          'module' => 'views',
          'delta' => 'articles-block_2',
          'region' => 'over_content',
          'weight' => 0,
        ),
        'views-articles-block_1' => array(
          'module' => 'views',
          'delta' => 'articles-block_1',
          'region' => 'over_content',
          'weight' => 1,
        ),
        'openx-1' => array(
          'module' => 'openx',
          'delta' => '1',
          'region' => 'over_content',
          'weight' => 2,
        ),
        'views-articles-block_3' => array(
          'module' => 'views',
          'delta' => 'articles-block_3',
          'region' => 'over_content',
          'weight' => 3,
        ),
        'views-articles-block_4' => array(
          'module' => 'views',
          'delta' => 'articles-block_4',
          'region' => 'over_content',
          'weight' => 4,
        ),
        'views-articles-block_5' => array(
          'module' => 'views',
          'delta' => 'articles-block_5',
          'region' => 'over_content',
          'weight' => 5,
        ),
        'openx-3' => array(
          'module' => 'openx',
          'delta' => '3',
          'region' => 'over_content',
          'weight' => 6,
        ),
        'views-articles-block_6' => array(
          'module' => 'views',
          'delta' => 'articles-block_6',
          'region' => 'over_content',
          'weight' => 7,
        ),
        'views-Bildegalleri-block_1' => array(
          'module' => 'views',
          'delta' => 'Bildegalleri-block_1',
          'region' => 'over_content',
          'weight' => 8,
        ),
        'views-articles-block_8' => array(
          'module' => 'views',
          'delta' => 'articles-block_8',
          'region' => 'over_content',
          'weight' => 9,
        ),
        'views-Blogger-block_2' => array(
          'module' => 'views',
          'delta' => 'Blogger-block_2',
          'region' => 'over_content',
          'weight' => 10,
        ),
        'views-Kommentarutdrag-block_2' => array(
          'module' => 'views',
          'delta' => 'Kommentarutdrag-block_2',
          'region' => 'over_content',
          'weight' => 11,
        ),
        'views-articles-block_7' => array(
          'module' => 'views',
          'delta' => 'articles-block_7',
          'region' => 'over_content',
          'weight' => 12,
        ),
        'openx-4' => array(
          'module' => 'openx',
          'delta' => '4',
          'region' => 'over_content',
          'weight' => 13,
        ),
        'views-Kommentarutdrag-block_1' => array(
          'module' => 'views',
          'delta' => 'Kommentarutdrag-block_1',
          'region' => 'left',
          'weight' => 1,
        ),
        'boxes-box-4bb00d6c' => array(
          'module' => 'boxes',
          'delta' => 'box-4bb00d6c',
          'region' => 'left',
          'weight' => 2,
        ),
        'simplenews-22' => array(
          'module' => 'simplenews',
          'delta' => '22',
          'region' => 'left',
          'weight' => 4,
        ),
        'boxes-box-3709d30d' => array(
          'module' => 'boxes',
          'delta' => 'box-3709d30d',
          'region' => 'left',
          'weight' => 5,
        ),
        'boxes-box-86cdd488' => array(
          'module' => 'boxes',
          'delta' => 'box-86cdd488',
          'region' => 'left',
          'weight' => 6,
        ),
        'boxes-box-c7e511c' => array(
          'module' => 'boxes',
          'delta' => 'box-c7e511c',
          'region' => 'left',
          'weight' => 7,
        ),
        'boxes-box-e57de1f' => array(
          'module' => 'boxes',
          'delta' => 'box-e57de1f',
          'region' => 'left',
          'weight' => 8,
        ),
        'boxes-box-756aa15a' => array(
          'module' => 'boxes',
          'delta' => 'box-756aa15a',
          'region' => 'left',
          'weight' => 9,
        ),
        'boxes-box-ad57121c' => array(
          'module' => 'boxes',
          'delta' => 'box-ad57121c',
          'region' => 'left',
          'weight' => 10,
        ),
        'google_analytics_reports-dashboard' => array(
          'module' => 'google_analytics_reports',
          'delta' => 'dashboard',
          'region' => 'left',
          'weight' => 11,
        ),
        'boxes-box-61c5e380' => array(
          'module' => 'boxes',
          'delta' => 'box-61c5e380',
          'region' => 'left',
          'weight' => 12,
        ),
        'boxes-box-5c93aa7' => array(
          'module' => 'boxes',
          'delta' => 'box-5c93aa7',
          'region' => 'left',
          'weight' => 13,
        ),
        'boxes-box-645d1de3' => array(
          'module' => 'boxes',
          'delta' => 'box-645d1de3',
          'region' => 'left',
          'weight' => 14,
        ),
        'views-popular-block' => array(
          'module' => 'views',
          'delta' => 'popular-block',
          'region' => 'left',
          'weight' => 15,
        ),
        'views-popular-block_1' => array(
          'module' => 'views',
          'delta' => 'popular-block_1',
          'region' => 'left',
          'weight' => 16,
        ),
        'boxes-box-7b6d4ea9' => array(
          'module' => 'boxes',
          'delta' => 'box-7b6d4ea9',
          'region' => 'left',
          'weight' => 17,
        ),
        'openx-6' => array(
          'module' => 'openx',
          'delta' => '6',
          'region' => 'right',
          'weight' => 1,
        ),
        'views-jobs-block_1' => array(
          'module' => 'views',
          'delta' => 'jobs-block_1',
          'region' => 'right',
          'weight' => 2,
        ),
        'openx-0' => array(
          'module' => 'openx',
          'delta' => '0',
          'region' => 'right',
          'weight' => 3,
        ),
        'fb_social-facepile' => array(
          'module' => 'fb_social',
          'delta' => 'facepile',
          'region' => 'right',
          'weight' => 4,
        ),
        'fb_social-recommendations' => array(
          'module' => 'fb_social',
          'delta' => 'recommendations',
          'region' => 'right',
          'weight' => 5,
        ),
        'fb_social-activityfeed' => array(
          'module' => 'fb_social',
          'delta' => 'activityfeed',
          'region' => 'right',
          'weight' => 6,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('OpenPublish Listing Page');
  $export['openpublish-listing_pages-frontpage'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openpublish-node_detail-article';
  $context->description = '';
  $context->tag = 'OpenPublish Detail Page';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'article' => 'article',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'kr_diverse-0' => array(
          'module' => 'kr_diverse',
          'delta' => 0,
          'region' => 'left',
          'weight' => 0,
        ),
        'views-also_read-block_1' => array(
          'module' => 'views',
          'delta' => 'also_read-block_1',
          'region' => 'left',
          'weight' => 1,
        ),
        'google_analytics_reports-path_mini' => array(
          'module' => 'google_analytics_reports',
          'delta' => 'path_mini',
          'region' => 'left',
          'weight' => 2,
        ),
        'views-jobs-block_1' => array(
          'module' => 'views',
          'delta' => 'jobs-block_1',
          'region' => 'right',
          'weight' => 0,
        ),
        'openx-0' => array(
          'module' => 'openx',
          'delta' => 0,
          'region' => 'right',
          'weight' => 1,
        ),
        'openx-6' => array(
          'module' => 'openx',
          'delta' => 6,
          'region' => 'right',
          'weight' => 2,
        ),
        'openx-1' => array(
          'module' => 'openx',
          'delta' => 1,
          'region' => 'over_content',
          'weight' => 0,
        ),
        'openx-4' => array(
          'module' => 'openx',
          'delta' => 4,
          'region' => 'over_content',
          'weight' => 1,
        ),
        'views-bilde_slider_node-block_1' => array(
          'module' => 'views',
          'delta' => 'bilde_slider_node-block_1',
          'region' => 'over_content',
          'weight' => 2,
        ),
        'kr_diverse-1' => array(
          'module' => 'kr_diverse',
          'delta' => 1,
          'region' => 'over_content',
          'weight' => 3,
        ),
        'disqus-disqus_comments' => array(
          'module' => 'disqus',
          'delta' => 'disqus_comments',
          'region' => 'under_content',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('OpenPublish Detail Page');
  $export['openpublish-node_detail-article'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openpublish-node_detail-author';
  $context->description = 'Author Page';
  $context->tag = 'OpenPublish Detail Page';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'author' => 'author',
      ),
      'options' => array(
        'node_form' => 1,
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Author Page');
  t('OpenPublish Detail Page');
  $export['openpublish-node_detail-author'] = $context;

  return $export;
}
