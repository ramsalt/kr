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
        'openx-0' => array(
          'module' => 'openx',
          'delta' => '0',
          'region' => 'right',
          'weight' => 1,
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
  $context->name = 'openpublish-listing_pages-blogs';
  $context->description = '';
  $context->tag = 'OpenPublish Listing Page';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'blogs' => 'blogs',
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
        'views-most_viewed_by_node_type-block' => array(
          'module' => 'views',
          'delta' => 'most_viewed_by_node_type-block',
          'region' => 'right',
          'weight' => 1,
        ),
        'views-most_commented_blogs-block_1' => array(
          'module' => 'views',
          'delta' => 'most_commented_blogs-block_1',
          'region' => 'right',
          'weight' => 2,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('OpenPublish Listing Page');

  $export['openpublish-listing_pages-blogs'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openpublish-listing_pages-events';
  $context->description = '';
  $context->tag = 'OpenPublish Listing Page';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'events' => 'events',
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
        'views-most_viewed_by_node_type-block' => array(
          'module' => 'views',
          'delta' => 'most_viewed_by_node_type-block',
          'region' => 'right',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('OpenPublish Listing Page');

  $export['openpublish-listing_pages-events'] = $context;
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
          'weight' => 4,
        ),
        'views-articles-block_4' => array(
          'module' => 'views',
          'delta' => 'articles-block_4',
          'region' => 'over_content',
          'weight' => 5,
        ),
        'views-articles-block_5' => array(
          'module' => 'views',
          'delta' => 'articles-block_5',
          'region' => 'over_content',
          'weight' => 6,
        ),
        'openx-3' => array(
          'module' => 'openx',
          'delta' => '3',
          'region' => 'over_content',
          'weight' => 7,
        ),
        'views-articles-block_6' => array(
          'module' => 'views',
          'delta' => 'articles-block_6',
          'region' => 'over_content',
          'weight' => 8,
        ),
        'openx-4' => array(
          'module' => 'openx',
          'delta' => '4',
          'region' => 'over_content',
          'weight' => 9,
        ),
        'views-popular-block' => array(
          'module' => 'views',
          'delta' => 'popular-block',
          'region' => 'left',
          'weight' => 1,
        ),
        'views-most_commented_blogs-block_1' => array(
          'module' => 'views',
          'delta' => 'most_commented_blogs-block_1',
          'region' => 'left',
          'weight' => 2,
        ),
        'poll-0' => array(
          'module' => 'poll',
          'delta' => '0',
          'region' => 'left',
          'weight' => 3,
        ),
        'openx-5' => array(
          'module' => 'openx',
          'delta' => '5',
          'region' => 'left',
          'weight' => 4,
        ),
        'views-jobs-block_1' => array(
          'module' => 'views',
          'delta' => 'jobs-block_1',
          'region' => 'right',
          'weight' => 0,
        ),
        'openx-6' => array(
          'module' => 'openx',
          'delta' => '6',
          'region' => 'right',
          'weight' => 2,
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
  $context->name = 'openpublish-listing_pages-multimedia';
  $context->description = '';
  $context->tag = 'OpenPublish Listing Page';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'multimedia' => 'multimedia',
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
        'views-most_viewed_multimedia-block' => array(
          'module' => 'views',
          'delta' => 'most_viewed_multimedia-block',
          'region' => 'right',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('OpenPublish Listing Page');

  $export['openpublish-listing_pages-multimedia'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openpublish-listing_pages-resources';
  $context->description = '';
  $context->tag = 'OpenPublish Listing Page';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'resources' => 'resources',
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
        'views-most_viewed_by_node_type-block' => array(
          'module' => 'views',
          'delta' => 'most_viewed_by_node_type-block',
          'region' => 'right',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('OpenPublish Listing Page');

  $export['openpublish-listing_pages-resources'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openpublish-multi-content_detail';
  $context->description = '';
  $context->tag = 'OpenPublish Detail Page';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'article' => 'article',
        'blog' => 'blog',
        'event' => 'event',
        'resource' => 'resource',
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
  t('OpenPublish Detail Page');

  $export['openpublish-multi-content_detail'] = $context;
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
        'views-jobs-block_1' => array(
          'module' => 'views',
          'delta' => 'jobs-block_1',
          'region' => 'right',
          'weight' => 0,
        ),
        'views-bilde_slider_node-block_1' => array(
          'module' => 'views',
          'delta' => 'bilde_slider_node-block_1',
          'region' => 'over_content',
          'weight' => 0,
        ),
        'fb_social_comments-comments' => array(
          'module' => 'fb_social_comments',
          'delta' => 'comments',
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
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-3' => array(
          'module' => 'block',
          'delta' => 3,
          'region' => 'right',
          'weight' => 0,
        ),
        'block-5' => array(
          'module' => 'block',
          'delta' => 5,
          'region' => 'right',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Author Page');
  t('OpenPublish Detail Page');

  $export['openpublish-node_detail-author'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openpublish-node_detail-blog';
  $context->description = '';
  $context->tag = 'OpenPublish Detail Page';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog' => 'blog',
      ),
      'options' => array(
        'node_form' => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'morelikethis-googlevideo' => array(
          'module' => 'morelikethis',
          'delta' => 'googlevideo',
          'region' => 'under_content',
          'weight' => 0,
        ),
        'morelikethis-taxonomy' => array(
          'module' => 'morelikethis',
          'delta' => 'taxonomy',
          'region' => 'right',
          'weight' => 0,
        ),
        'morelikethis-flickr' => array(
          'module' => 'morelikethis',
          'delta' => 'flickr',
          'region' => 'right',
          'weight' => 1,
        ),
        'block-3' => array(
          'module' => 'block',
          'delta' => '3',
          'region' => 'right',
          'weight' => 2,
        ),
        'blog-0' => array(
          'module' => 'blog',
          'delta' => '0',
          'region' => 'right',
          'weight' => 3,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('OpenPublish Detail Page');

  $export['openpublish-node_detail-blog'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openpublish-node_detail-event';
  $context->description = '';
  $context->tag = 'OpenPublish Detail Page';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'event' => 'event',
      ),
      'options' => array(
        'node_form' => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'morelikethis-taxonomy' => array(
          'module' => 'morelikethis',
          'delta' => 'taxonomy',
          'region' => 'right',
          'weight' => 0,
        ),
        'morelikethis-flickr' => array(
          'module' => 'morelikethis',
          'delta' => 'flickr',
          'region' => 'right',
          'weight' => 1,
        ),
        'block-3' => array(
          'module' => 'block',
          'delta' => 3,
          'region' => 'right',
          'weight' => 2,
        ),
        'morelikethis-googlevideo' => array(
          'module' => 'morelikethis',
          'delta' => 'googlevideo',
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

  $export['openpublish-node_detail-event'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'openpublish-node_detail-resource';
  $context->description = '';
  $context->tag = 'OpenPublish Detail Page';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'resource' => 'resource',
      ),
      'options' => array(
        'node_form' => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'morelikethis-taxonomy' => array(
          'module' => 'morelikethis',
          'delta' => 'taxonomy',
          'region' => 'right',
          'weight' => 0,
        ),
        'morelikethis-flickr' => array(
          'module' => 'morelikethis',
          'delta' => 'flickr',
          'region' => 'right',
          'weight' => 1,
        ),
        'block-3' => array(
          'module' => 'block',
          'delta' => 3,
          'region' => 'right',
          'weight' => 2,
        ),
        'morelikethis-googlevideo' => array(
          'module' => 'morelikethis',
          'delta' => 'googlevideo',
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

  $export['openpublish-node_detail-resource'] = $context;
  return $export;
}
