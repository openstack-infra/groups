#!/bin/bash
#
# Build groups distribution from local filesystem instead of fetching
# directly from git
#

TARGET_DIR=publish

drush make drupal-org-core.make $TARGET_DIR
mkdir -p $TARGET_DIR/profiles/groups
rsync -av --exclude=$TARGET_DIR . $TARGET_DIR/profiles/groups/
drush make --no-core --no-cache --contrib-destination=profiles/groups drupal-org.make $TARGET_DIR.contrib
rsync -av $TARGET_DIR.contrib/* $TARGET_DIR/
rm -rf $TARGET_DIR.contrib
