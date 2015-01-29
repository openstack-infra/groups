#!/bin/bash
#
# Create a new language skeleton from pot template files
#

if [ -z "$1" ]; then
    echo "Usage: $0 <lang-code>"
    exit 1
fi

LANG_CODE="$1"

PROFILE_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )/.." && pwd )
mkdir -p $PROFILE_DIR/translations/$LANG_CODE
ls -1 $PROFILE_DIR/translations/templates/*.pot | while read f; do
  FILENAME=`basename -s .pot $f`
  SRC=$PROFILE_DIR/translations/templates/$FILENAME.pot
  DEST=$PROFILE_DIR/translations/$LANG_CODE/$FILENAME.$LANG_CODE.po
  cp $SRC $DEST
done