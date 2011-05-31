<?php

/**
 * @file
 * Template for job content type.
 * 
 * Available variables:
 * - $type: Content type (article).
 * - $field_deck: Used to determine visibility of $field_deck_value.
 * - $field_deck_value: The article's deck text.
 * - $authors: List of authors.
 * - $node_created: The article's post date.
 * - $node_created_timestamp: The article's post date in timestamp format.
 * - $body: Actual body content of the article.
 * - $main_image: The article's main image.
 * - $main_image_desc: The main image's description.
 * - $main_image_credit: The main image's credit.
 * - $show_authors: Determines whether the "About the Authors" block is shown or not.
 * - $author_profiles: an array of author profiles to display. Each $author in $author_profiles contains:
 *   - $author->title: Author's name.
 *   - $author->jobtitle: Author's job title.
 *   - $author->teaser: Author's teaser text. 
 *   - $author->photo: Author's photo thumbnail. 
 * - $calais_geo_map: Calais geomapping data.
 * - $related_terms_links: Related taxonomy links.
 * - $themed_links: Themed links.
 * 
 * @see openpublish_node_article_preprocess()
 */
 
?>

<div class="body-content job">
  <div property="dc:description"><?php  print $body; ?></div>

</div>

<?php print $related_terms_links; ?>
<?php print $themed_links; ?>