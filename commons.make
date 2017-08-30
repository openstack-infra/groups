api = 2
core = 7.x

; Download the Commons install profile and recursively build all its dependencies.
projects[commons][type] = "profile"
projects[commons][version] = "3.39"
projects[commons][patch][] = "patches/0005-commons-libraries-search-paths-alter.patch"
projects[commons][patch][] = "patches/0004-accomodate-flag-v3.patch"
projects[commons][patch][] = "patches/0009-commons-flag-v3.patch"
projects[commons][patch][] = "patches/0010-commons-activity-streams-warning.patch"
projects[commons][patch][] = "patches/0011-commons-media-beta12.patch"
projects[commons][patch][] = "patches/0012-commons-title-alpha9.patch"
projects[commons][patch][] = "patches/0013-commons-views-3.15.patch"
projects[commons][patch][] = "patches/0014-commons-metatag-1.21.patch"
projects[commons][patch][] = "patches/0015-commons-media-2.0.patch"
projects[commons][patch][] = "patches/0016-commons-file_entity-2.3.patch"
projects[commons][patch][] = "patches/0017-commons-media-2.9.patch"
projects[commons][patch][] = "patches/0018-commons-views-3.18.patch"
projects[commons][patch][] = "patches/0019-commons-entity-reference-1.5.patch"
projects[commons][patch][] = "patches/0020-commons-flag-unsupported-operands.patch"
