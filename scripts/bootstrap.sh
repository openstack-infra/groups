#!/bin/bash
#
# Bootstrap a minimal environment required to build
# a Drupal distribution tarball on Ubuntu 12.04LTS (precise)
#

set -xe

export DEBIAN_FRONTEND=noninteractive
apt-get update
apt-get install -y unzip php5-mysql php5-gd php5-cli libapache2-mod-php5 mysql-server mysql-client php-pear git ruby-bundler

# install drush 6.0.0
pear channel-discover pear.drush.org
pear install drush/drush-6.0.0
pear install Console_Table-1.1.3

# add drupal-site-deployment drush extension
wget https://github.com/mkissam/drush-dsd/archive/v0.10.tar.gz -O - | tar -xz
mv drush-dsd-0.10 /usr/share/php/drush/commands/dsd
