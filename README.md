OpenStack groups portal
=======================

Prerequisites
-------------

* drush 7.x-5.8
* LAMP environment capable of running Drupal 7.x

Build distribution
==================

make stub file
---------------

Create build-osgroups.make file with following content:
```
api = "2"
core = "7.x"

; Include the definition of how to build Drupal core directly, including patches.
;includes[] = "drupal-org-core.make"

projects[drupal][type] = "core"

; Download the OpenStack Groups install profile and recursively build all its dependencies.
projects[osgroups][type] = "profile"
projects[osgroups][download][type] = "git"
projects[osgroups][download][url] = "https://github.com/openstack-infra/groups.git"
projects[osgroups][download][branch] = "master"
```

make distribution
-----------------

```bash
$> drush make build-osgroups.make osgroups-dev.local
```

