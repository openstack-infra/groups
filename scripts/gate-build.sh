#!/usr/bin/env bash

# Gating test script for Community portal
# 1. prepare mysql database
# 2. build distribution tarball
# 3. install "groups" profile
#
# Prerequisites:
#   bootstrap.sh required for setup php/drush environment.
#   git clone the project into groups directory.

set -xe

# create mysql database
mysql <<EOF
CREATE DATABASE groups;
GRANT SELECT, INSERT, UPDATE, DELETE, CREATE, DROP, INDEX, ALTER
  ON groups.*
  TO 'groups'@'localhost' IDENTIFIED BY 'password';
EOF

# build distribution tarball
drush make build-groups.make dist
tar -czf groups-snapshot.tar.gz dist/

# drush alias template
cat >~/.drush/aliases.drushrc.php <<EOF
<?php

\$aliases['groups-dev'] = array(
  'root' => '/srv/vhosts/groups.local/w',
  'dsd-root' => '/srv/vhosts/groups.local',
  'uri' => 'groups.local',
  'databases' => array(
    'default' => array(
      'driver' => 'mysql',
      'username' => 'groups',
      'password'  => 'password',
      'port' => '',
      'host' => 'localhost',
      'database' => 'groups',
    ),
  ),
  'file-owner' => 'root',
  'file-group' => 'www-data',
  'variables' => array(
    'site_name' => 'Groups Test Deployment',
  ),
  'profile' => 'groups',
  'default-admin-password' => 'admin',
);
EOF

mkdir -p /srv/vhosts/groups.local
drush dsd-init @groups-dev groups-snapshot.tar.gz
drush @groups-dev status
