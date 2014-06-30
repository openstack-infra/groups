#!/bin/bash
#
# Build groups distribution from local filesystem instead of fetching
# directly from git
#

TARGET_DIR=${TARGET_DIR:-publish}
PROFILE_NAME=${PROFILE_NAME:-groups}

if [ ! -z "$1" ]; then
  TARGET_DIR=$1
fi

drush make drupal-org-core.make $TARGET_DIR
mkdir -p $TARGET_DIR/profiles/$PROFILE_NAME
rsync -av --exclude=$TARGET_DIR --exclude=drush . $TARGET_DIR/profiles/$PROFILE_NAME/
drush make --no-core --no-cache --contrib-destination=profiles/$PROFILE_NAME drupal-org.make $TARGET_DIR.contrib
rsync -av $TARGET_DIR.contrib/* $TARGET_DIR/
rm -rf $TARGET_DIR.contrib
