#!/bin/bash
for ((i=1;i<=250;i+=1)); do
drush --uri="http://kommunal-rapport.no" solr-index
done
