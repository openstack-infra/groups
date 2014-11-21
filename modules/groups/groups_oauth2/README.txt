Description
-----------

This module provides a basic oauth2 authentication for openstackid.org provider. Supports
fetching of first and family name, and fetch profile picture url. As openstackid provider
requires https communication, and the profile image assets not available through ssl,
the groups_auth2 module supports fetching of profile pictures into a local directory.

Requirements
------------
Drupal 7.x
Properly configured Oauth2 provider.

Variables
---------

oauth2_fetch_profile_picture:boolean
If set to TRUE, downloads profile picture during login into the public://profile-images
directory. Default value is FALSE.

groups_oauth2_provider:string
Contains the url of oauth2 provider. For openstackid, set it to https://openstackid.org

groups_oauth2_client_id:string
The client id assigned for this specific application.

groups_oauth2_client_secret:string
The client secret assigned for the client_id.