========== 1.2 ==========
- log where updated to orderby ID (latest entry)
- updating default.inc
- new script to handle resized images on the fly "img src="includes/scripts/image.php?w=1000&fit=0&h=120&file=refined.png"" 

========== 1.1 ==========
- sql table added
- docblock added to a helpers method
- admin.js changed to accomidate more than one pager
- added pager to log
- two pagers on edit_page one for sub-pages and one for content
- some fixes in pager.class.php
- upon calling a new pager the pager class will generate some js for admin.js to grab. make sure page_key, and amt_key are never the same when using more than one pager.

========== 1.0 ==========
- scripts in admin are now in admin/scripts, it needed organization.
- log is out of its own folder, and now correctly in admin under users.
- pagenation class, and implimentation on several pages.
- updated add_user.inc 
- updated the search inputs to say filter instead, because they dont search
- trying to remove hashs from links.
- css fixes to admin 
- removed old css
- admin_ajax has a pager function to go with php pager class
- $helpers->setParam will force page redirect even after headers have sent.

========== 0.9 ==========
- When creating a user, validation will now check to see if there is already a user with that username.
- Username cannot be edited any longer.
- log updates, you can now purge the log using helpers truncate method
- added jquery.cookie.js this will help remmeber what state the nav should be in.
- logo in config will now have the already selected logo set as its value. Now you dont have to reselect a new one everytime you save.
- log will now show up under users, its still in its own subfolder and will be changed in the future to be contained in the admin where it should be 
- view class now has two new methods $view->show_content, and $view->show_label
- bootstrap theme for the front end, making it look more presentable
- css updates

========== 0.8.2 ==========

- added 404 page (non customizable, if the page url isn’t in the db it will auto forward to 404, so you need a 404 page under pages).
- fix in app/views/body.inc
- fix in labels.inc

========== 0.8.1 ==========
- Better and more thought out sanitization added to add/update. $helpers->custom_clean($passin,$js,$html, look in helpers for the whole list)
- log is fixed, purge button added but not functional yet.
- minor template fixes for admin
- minor css fixes for admin
- $helpers has an added sqlDelete() method that does not function yet.


========== 0.8.0 BETA ==========

- Upgraded from alpha to beta.
- helper class now handles sqlSelect(). This involves helpers having its own PDO method.
- New UI, tons of small changes to accomidate (JS/CSS/INC)
- Font Awesome Added (not all symbols updated yet)
- put in some docblocks in helpers
- old css file saved, but will eventually be phazed out.



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
- removed access check in upload.php
- added favicon to admin, and changed title to use helpers::url(base)
- updated labels token.
- can now config if you want  uploads (100% or 0%, no user permissions yet)
- ajaxed out uploaded.inc 
- template debug is in config(true/false), error reporting is configable (true/false), timezone is configable string ('America/New_York')
- updated demo sites footer using wrong $_config calls
- css for ajaxed uploaded.inc to confirm delete
- error reporting is configable,
- delete image script in admin, for deleting images in uploads.


========== 0.5 ALPHA ==========

- Complete overhaul of file system.
- changed token security system to be easier, and less stupid, stop looking for specific tokens every time and just look for ‘token’.
- created an app.php file to run all necessary classes.
- fixed some issues with the logs index, and admins index (if no session make it null, no extra session_start()).
- removed index.html from folders i didn’t want people to access from the browser and replaced it with a proper .htaccess block
- image upload checks for access level 1, just in case.. this will be updated in 0.6, however in the future where different users have different permissions it will most likely use the same concept. This implementation actually breaks image uploading, don’t use 0.5 for image uploading.
- updated several php starts to use php keyword <? => <?php just incase.
- updated add page to check for parent page.
- dashboard by user is now available, go into users view find a user and change their user comments, this will appear in their dashboard.
- missed some quotes, added them in.
- edit_page updates include checking for subpage and template correctly
- edit user now says ‘edit user_fullname’.
- footer in admin changed to be responsive
- WYSIWYG added to user comments, and page content, this will make it much easier for users to quickly make edits they want.
- AuthView is now appView, authModel is now appModel
- appView checks for admin/log/site to pick specific folders, it also has a debug setting $tpl_debug in app_view.php
- removed the old responsive table js in favor of a css based fix.
- responsiveness for deleting should now be better, not perfect.
- admin js function to check for external links and open them in a new window - hand in hand with dashboard, and another to check for query strings in url.
- WYSIWYG will only run on ?type=edit_page and ?type=edit_user, check the JS to change this around.
- updated getQuery() to check for isset correctly
- php will throw errors on page, to help development, will be configurable in 0.6



 