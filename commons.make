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
