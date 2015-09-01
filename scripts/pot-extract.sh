#!/usr/bin/env bash

# Extract translation template files from groups modules
#
# templates will be created in translations/ directory as
# <module-name>-<version>.pot
#
# Usage:
# cd profiles/groups
# ./scripts/pot-extract.sh

PROFILE_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )/.." && pwd )
mkdir -p $PROFILE_DIR/translations/templates
MODULE_DIR=${PROFILE_DIR}/modules/groups/
echo $PROFILE_DIR
ls -1 $MODULE_DIR | while read f; do
  cd $MODULE_DIR/$f
  drush potx single
  # transform absolute path to relative and write output to .pot file
  # remove new lines from EOF and EOL whitespaces
  POT_FILE=$PROFILE_DIR/translations/templates/$f-7.x-1.0.pot
  cat $PROFILE_DIR/../../general.pot | \
    sed -e "s=$MODULE_DIR==" | \
    sed -e :a -e '/^\n*$/{$d;N;ba' -e '}' | \
    sed 's/[ \t]*$//' > $POT_FILE
done
# clean-up general.pot
rm $PROFILE_DIR/../../general.pot
