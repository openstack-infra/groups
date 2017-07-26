#!/usr/bin/env bash -x

# Build groups distribution from local filesystem instead of fetching
# directly from git

TARGET_DIR=${TARGET_DIR:-publish}
PROFILE_NAME=${PROFILE_NAME:-groups}
THEME_NAME=${THEME_NAME:-openstack_bootstrap}

if [ ! -z "$1" ]; then
  TARGET_DIR=$1
fi

# build core
echo "=== Build Drupal Core ==="
drush make -v drupal-org-core.make $TARGET_DIR

# build drupal commons
echo "=== Build Drupal Commons ==="
drush make -v --no-core --no-cache commons.make $TARGET_DIR.commons
rsync -a $TARGET_DIR.commons/* $TARGET_DIR/
rm -rf $TARGET_DIR.commons

# build groups custom modules
echo "=== Build Custom Modules ==="
mkdir -p $TARGET_DIR/profiles/$PROFILE_NAME
rsync -a --exclude=$TARGET_DIR --exclude=drush . $TARGET_DIR/profiles/$PROFILE_NAME/
drush make -v --no-core --no-cache --contrib-destination=profiles/$PROFILE_NAME drupal-org.make $TARGET_DIR.contrib
rsync -a $TARGET_DIR.contrib/* $TARGET_DIR/
rm -rf $TARGET_DIR.contrib

# build theme css from sass files
cwd=$(pwd)
cd $TARGET_DIR/profiles/$PROFILE_NAME/themes/$THEME_NAME
if [ -f Gemfile ]; then
  mkdir .bundled_gems
  export GEM_HOME=`pwd`/.bundled_gems
  gem install bundler --no-rdoc --no-ri
  $GEM_HOME/bin/bundle install
  $GEM_HOME/bin/bundle exec compass compile
  # cleanup
  rm -rf .bundled_gems .sass-cache
fi
cd $cwd
