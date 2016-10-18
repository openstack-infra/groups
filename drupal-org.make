api = 2
core = 7.x

; Contributed modules.

projects[privatemsg][type] = "module"
projects[privatemsg][subdir] = "contrib"
projects[privatemsg][version] = "1.4"

; Add preliminary Views integration.
; http://drupal.org/node/1573000
projects[privatemsg][patch][] = "http://drupal.org/files/privatemsg-1573000-64.patch"

; Enable privatemsg_realname when realname is enabled.
; https://drupal.org/node/2070719
projects[privatemsg][patch][] = "http://drupal.org/files/2077223-privatemsg-realname-enabled-1.patch"

projects[privatemsg_notify_sender][type] = "module"
projects[privatemsg_notify_sender][subdir] = "contrib"
projects[privatemsg_notify_sender][version] = "1.1"

projects[elysia_cron][type] = "module"
projects[elysia_cron][subdir] = "contrib"
projects[elysia_cron][version] = "2.3"

projects[google_analytics][type] = "module"
projects[google_analytics][subdir] = "contrib"
projects[google_analytics][version] = "2.3"

projects[oembed][type] = "module"
projects[oembed][subdir] = "contrib"
projects[oembed][download][type] = "git"
projects[oembed][download][url] = "http://git.drupal.org/project/oembed.git"
projects[oembed][download][branch] = "7.x-1.x"
projects[oembed][download][revision] = "9aa5303"

; Remove the media submodule as it conflicts with the Media: oEmbed module.
; https://drupal.org/node/2269745#comment-8796261
projects[oembed][patch][] = "https://drupal.org/files/issues/remove-media-submodule-2269745-2.patch"

projects[geophp][version] = "1.7"
projects[geophp][type] = "module"
projects[geophp][subdir] = "contrib"

projects[geocoder][version] = "1.2"
projects[geocoder][type] = "module"
projects[geocoder][subdir] = "contrib"

projects[geofield][version] = "2.1"
projects[geofield][type] = "module"
projects[geofield][subdir] = "contrib"

projects[leaflet][version] = "1.1"
projects[leaflet][type] = "module"
projects[leaflet][subdir] = "contrib"

projects[leaflet_mapbox][version] = "1.5"
projects[leaflet_mapbox][type] = "module"
projects[leaflet_mapbox][subdir] = "contrib"

projects[leaflet_more_maps][version] = "1.9"
projects[leaflet_more_maps][type] = "module"
projects[leaflet_more_maps][subdir] = "contrib"

projects[feeds][type] = "module"
projects[feeds][subdir] = "contrib"
projects[feeds][version] = "2.0-alpha9"
; fix broken date import
; https://www.drupal.org/node/2237177
projects[feeds][patch][] = "https://www.drupal.org/files/issues/feeds-date_import_fix.patch"

projects[feeds_jsonpath_parser][type] = "module"
projects[feeds_jsonpath_parser][subdir] = "contrib"
projects[feeds_jsonpath_parser][version] = "1.0-beta2"

projects[job_scheduler][type] = "module"
projects[job_scheduler][subdir] = "contrib"
projects[job_scheduler][version] = "2.0-alpha3"

projects[drush_feeds_import][type] = "module"
projects[drush_feeds_import][subdir] = "contrib"
projects[drush_feeds_import][download][type] = "git"
projects[drush_feeds_import][download][url] = "http://git.drupal.org/sandbox/enzo/1865202.git"
projects[drush_feeds_import][download][branch] = "master"
projects[drush_feeds_import][download]revision] = "bd7efd4e46d51d40b97a2954771e08cd669a3410"
; $feed->feed_nid check in _feed_import
; https://drupal.org/node/1888356
projects[drush_feeds_import][patch][] = "https://drupal.org/files/drush_feeds_import-nofeednidfix-1888356-3.patch"

projects[feeds_fetcher_directory][type] = "module"
projects[feeds_fetcher_directory][subdir] = "contrib"
projects[feeds_fetcher_directory][version] = "2.0-beta5"
; fix configFormValidate() errors
; https://drupal.org/node/2023775
projects[feeds_fetcher_directory][patch][] = "https://drupal.org/files/feeds_fetcher_directory-config-form-validate-errors.patch"

projects[jquery_update][type] = "module"
projects[jquery_update][subdir] = "contrib"
projects[jquery_update][version] = "2.7"

projects[panels_ajax_tab][type] = "module"
projects[panels_ajax_tab][subdir] = "contrib"
projects[panels_ajax_tab][version] = "1.x-dev"

projects[date_ical][type] = "module"
projects[date_ical][subdir] = "contrib"
projects[date_ical][version] = "3.4"

projects[ds][type] = "module"
projects[ds][subdir] = "contrib"
projects[ds][version] = "2.8"

projects[markdown][type] = "module"
projects[markdown][subdir] = "contrib"
projects[markdown][version] = "1.2"

projects[smtp][type] = "module"
projects[smtp][subdir] = "contrib"
projects[smtp][version] = "1.2"

projects[potx][version] = 3.x-dev
projects[potx][type] = "module"
projects[potx][subdir] = "contrib"

projects[registry_rebuild][version] = 2.4
projects[registry_rebuild][type] = "module"
projects[registry_rebuild][subdir] = "contrib"

projects[tzfield][version] = "1.1"
projects[tzfield][type] = "module"
projects[tzfield][subdir] = "contrib"

; Contributed themes.

projects[zen][type] = "theme"
projects[zen][subdir] = "contrib"
projects[zen][version] = "5.5"

projects[bootstrap][type] = "theme"
projects[bootstrap][subdir] = "contrib"
projects[bootstrap][version] = "3.0"

; Libraries.
; NOTE: These need to be listed in http://drupal.org/packaging-whitelist.
libraries[placeholder][download][type] = "get"
libraries[placeholder][type] = "libraries"
libraries[placeholder][download][url] = "https://github.com/mathiasbynens/jquery-placeholder/archive/v2.0.7.tar.gz"

libraries[leaflet][download][type] = "get"
libraries[leaflet][type] = "libraries"
libraries[leaflet][download][url] = "http://cdn.leafletjs.com/downloads/leaflet-0.7.3.zip"
libraries[leaflet][destination] = "libraries"

libraries[iCalcreator][type] = "libraries"
libraries[iCalcreator][download][type] = "get"
libraries[iCalcreator][download][url] = "https://github.com/iCalcreator/iCalcreator/archive/e3dbec2cb3bb91a8bde989e467567ae8831a4026.zip"
libraries[iCalcreator][destination] = "libraries"

libraries[feeds_jsonpath_parser][download][type] = get
libraries[feeds_jsonpath_parser][download][url] = https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/jsonpath/jsonpath-0.8.1.php
libraries[feeds_jsonpath_parser][destination] = modules/contrib
libraries[feeds_jsonpath_parser][install_path] = profiles/groups

libraries[chartjs][download][type] = "get"
libraries[chartjs][type] = "libraries"
libraries[chartjs][download][url] = "https://github.com/nnnick/Chart.js/archive/v1.0.1.tar.gz"
libraries[chartjs][destination] = "libraries"
