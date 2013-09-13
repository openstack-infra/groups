api = 2
core = 7.x

; Include the definition of how to build Drupal core directly, including patches.
includes[] = "drupal-org-core.make"

; Download the Groups install profile and recursively build all its dependencies.
projects[groups][type] = "profile"
projects[groups][download][type] = "git"
projects[groups][download][url] = "https://github.com/openstack-infra/groups.git"
projects[groups][download][branch] = "master"
