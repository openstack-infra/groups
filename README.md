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

Create build-groups.make file with following content:
```
api = 2
core = 7.x

; Include the definition of how to build Drupal core directly, including patches.
includes[] = "drupal-org-core.make"

; Download the Groups install profile and recursively build all its dependencies.
projects[groups][type] = "profile"
projects[groups][download][type] = "git"
projects[groups][download][url] = "https://github.com/openstack-infra/groups.git"
projects[groups][download][branch] = "master"
```

make distribution
-----------------

```bash
$> drush make build-groups.make groups-dev.local
```

release tarballs
----------------

Development and release tarballs available at http://tarballs.openstack.org/groups

