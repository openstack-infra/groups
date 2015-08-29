#!/usr/bin/env bash

set -e

languages=(zh-hant zh-hans ja ko vi ru pl de fr es it pt-pt hu ar tr)

echo "
api = 2
core = 7.x

; Notice: we are using 'profile' as a project type here, because drush make
; doesn't support direct download of contribution language files
;
"

for i in "${languages[@]}"; do
echo "
projects[translation_${i}][type] = \"profile\"
projects[translation_${i}][directory_name] = \"groups/translations\"
projects[translation_${i}][download][type] = \"file\"
projects[translation_${i}][download][url] = \"http://ftp.drupal.org/files/translations/7.x/commons/commons-7.x-3.3-rc2.${i}.po\""
done
