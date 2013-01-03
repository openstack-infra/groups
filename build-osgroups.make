api = 2
core = 7.x

; Include the definition of how to build Drupal core directly, including patches.
includes[] = "drupal-org-core.make"

; Download the OpenStack Groups install profile and recursively build all its dependencies.
projects[osgroups][type] = "profile"
projects[osgroups][download][type] = "git"
projects[osgroups][download][url] = "https://github.com/marton-kiss/openstack-groups.git"
projects[osgroups][download][branch] = "master"
