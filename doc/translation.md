Groups portal translation howto
===============================

Overview
--------

The Groups portal based on Drupal Commons, which is based on Drupal distribution
extended with community features and functionality. If you want to translate
the user interface to your local language basically you need to follow the
same rules that are used for a standard Drupal deployment. As Drupal is based
on modules, we need to consider the concept that we are translating the strings
defined in those modules. The upstream modules are usually translated
by the Drupal community, so in our case we need to focus on our custom
modules only in modules/groups directory.

### Directory structure

      [profiles/groups]
        ...
        translations/
          templates/                     - translation template files (.pot)
          <langcode>/                    - directory with langauge specific .po files
            groups_<name>-<version>.po  - translated module resources
        scripts/
          pot-extract.sh
          pot-lang.sh

### Translation process

The localization files can be found under translations/<langcode> directory,
if you are using a deployed portal, the full path is
profiles/groups/translations/<langcode>. If your language is not present
there, you need to create the skeleton, see the `how to add a new language`
section.

After you successfully modified the .po files, either manually or using a tool
like PoEdit, simply follow the steps of the Contribution Guide and
send your patch for a review.

If you want to test the changes locally, follow the steps of
`Import updated .po files into Drupal`

### Add a new language

    $> bash scripts/pot-lang.sh <langcode>

`Notice` the language codes are based on ISO 639 standard.

### Update translation template files (.pot)

When a new feature is added to our custom module, or some interface elements
are changed in module files, it is important to regenerate the translation
template files.

    $> bash scripts/pot-extract.sh

Carefully check the output of this script. If you experience
any lines marked with error, try to solve the issue in Drupal
module, and upload a patch with a resolution to groups repository.

### Import updated .po files into Drupal

    $> drush l10n-update-refresh
    $> drush l10n-update

This two command will refetch the .po files and import the translation strings
into Drupal database.

### FAQ

#### What to do when an interface element is missing from po files?

The elements rendered by Drupal portal can be originated from multiple places,
it can be a content, or a translatable string in Drupal module. If you
found the element in a module, but it is not covered by the t() function
the solution is easy, cover the string with t(), regenerate the .pot files
and synchronize the .po file content. (PoEdit and GetText utils are
supporting the merge process, so you need to translate the updated
resources only, and old translations won't lost)

`Example`

    -- function groups_homepage_views_pre_build(&$view) {
    --   ...
    --   $view->display_handler->set_option('title', 'Upcoming Events');

    +++ function groups_homepage_views_pre_build(&$view) {
    +++  ...
    +++  $view->display_handler->set_option('title', t('Upcoming Events'));

References
----------

[1] OpenStack Developer's Guide
http://docs.openstack.org/infra/manual/developers.html

[2] OpenStack Groups Portal Contribution Guide
https://groups.openstack.org/content/openstack-groups-portal-contribution-guide

[3] Drupal Localization
https://localize.drupal.org

[4] ISO 639 Language codes
http://people.w3.org/rishida/names/languages.html