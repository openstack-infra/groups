#!/usr/bin/env bash

set -e

modules=(commons_activity_streams commons_featured commons_notices commons_profile_social commons_user_profile_pages commons_body commons_follow commons_notify commons_utility_links commons_bw commons_groups commons_pages commons_radioactivity commons_content_moderation commons_like commons_search commons_wysiwyg commons_documents commons_location commons_posts commons_site_homepage commons_events commons_misc commons_profile_base commons_topics commons_social_sharing commons_trusted_contacts)
themes=(commons_origins)

echo "
api = 2
core = 7.x

; Commons modules.
"

for i in "${modules[@]}"; do
  echo "
projects[${i}][type] = \"module\"
projects[${i}][subdir] = \"commons\"
projects[${i}][download][url] = \"http://git.drupal.org/project/${i}.git\"
projects[${i}][download][branch] = \"7.x-3.x\""
done

for i in "${themes[@]}"; do
  echo "
projects[${i}][type] = \"theme\"
projects[${i}][subdir] = \"commons\"
projects[${i}][download][url] = \"http://git.drupal.org/project/${i}.git\"
projects[${i}][download][branch] = \"7.x-3.x\""
done
