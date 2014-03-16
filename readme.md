========== 0.7.1 ==========

- Each individual template checks for permissions before displaying.

========== 0.7.0 ==========

- User Permissions on a user by user basis, no user groups yet.

- the mandetory css changes.

- i think i fixed a x-scrollbar issue, hopefully.

- user permissions for 0.7.0 are nav only, user could still travel to the page.

- image check in uploaded  before resizing, dont want to try to resize a non-image that throws an error.

- added normalize.css to admin.

- updated skeleton.css hopefully for the better.

========== 0.6.3 ==========

- image delete was broken, now fixed.

========== 0.6.2 ==========

- deleted unessicary things in delete_image.php, and when you delete an image its resized counter part is also unlinked.

- edit_config.inc tons of changes to accomidate the image chooser

- uploaded.inc now has the ability to rename an image (or other file). The js will only show the checkmark to accept a new name.

- css for wysiwyg, overlay importances, image chooser, uploadeds pictures, rename stuff, added quotes around image urls

- wysiwyg somewhat responsive.

- added equalheight() incase i need it.

- image chooser function

- updated jquery.min.js

- helpers php has a image resizer $helpers->smart_resize_image(opts);


========== 0.6.1 ==========

more options in config, yay.

-removed access check in upload.php

-added favicon to admin, and changed title to use helpers::url(base)

-updated labels token.

-can now config if you want  uploads (100% or 0%, no user permissions yet)

-ajaxed out uploaded.inc 

-template debug is in config(true/false), error reporting is configable (true/false), timezone is configable string ('America/New_York')

-updated demo sites footer using wrong $_config calls

-css for ajaxed uploaded.inc to confirm delete

-error reporting is configable,

-delete image script in admin, for deleting images in uploads.


========== 0.5 ==========

-Complete overhaul of file system.

-changed token security system to be easier, and less stupid, stop looking for specific tokens every time and just look for ‘token’.

-created an app.php file to run all necessary classes.

-fixed some issues with the logs index, and admins index (if no session make it null, no extra session_start()).

-removed index.html from folders i didn’t want people to access from the browser and replaced it with a proper .htaccess block

-image upload checks for access level 1, just in case.. this will be updated in 0.6, however in the future where different users have different permissions it will most likely use the same concept. This implementation actually breaks image uploading, don’t use 0.5 for image uploading.

-updated several php starts to use php keyword <? => <?php just incase.

-updated add page to check for parent page.

-dashboard by user is now available, go into users view find a user and change their user comments, this will appear in their dashboard.

-missed some quotes, added them in.

-edit_page updates include checking for subpage and template correctly

-edit user now says ‘edit user_fullname’.

-footer in admin changed to be responsive

-WYSIWYG added to user comments, and page content, this will make it much easier for users to quickly make edits they want.

-AuthView is now appView, authModel is now appModel

-appView checks for admin/log/site to pick specific folders, it also has a debug setting $tpl_debug in app_view.php

-removed the old responsive table js in favor of a css based fix.

-responsiveness for deleting should now be better, not perfect.

-admin js function to check for external links and open them in a new window - hand in hand with dashboard, and another to check for query strings in url.

-WYSIWYG will only run on ?type=edit_page and ?type=edit_user, check the JS to change this around.

-updated getQuery() to check for isset correctly

-php will throw errors on page, to help development, will be configurable in 0.6



 