# ************************************************************
# Sequel Pro SQL dump
# Version 4096
#
# http://www.sequelpro.com/
# http://code.google.com/p/sequel-pro/
#
# Host: refineddesigns.net (MySQL 5.5.38-35.2-log)
# Database: refinee9_framework_db
# Generation Time: 2014-10-18 18:57:48 +0000
# ************************************************************


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;


# Dump of table config
# ------------------------------------------------------------

CREATE TABLE `config` (
  `site_name` varchar(50) COLLATE latin1_general_ci NOT NULL,
  `global_logo` varchar(100) COLLATE latin1_general_ci NOT NULL,
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `extra_js` varchar(1000) COLLATE latin1_general_ci DEFAULT NULL,
  `extra_css` varchar(1000) COLLATE latin1_general_ci DEFAULT NULL,
  `version` varchar(10) COLLATE latin1_general_ci DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_general_ci;

LOCK TABLES `config` WRITE;
/*!40000 ALTER TABLE `config` DISABLE KEYS */;

INSERT INTO `config` (`site_name`, `global_logo`, `id`, `extra_js`, `extra_css`, `version`)
VALUES
	('','',1,'//test','/*test*/','1.34');

/*!40000 ALTER TABLE `config` ENABLE KEYS */;
UNLOCK TABLES;


# Dump of table content
# ------------------------------------------------------------

CREATE TABLE `content` (
  `content_order` int(3) NOT NULL,
  `page_id` int(11) NOT NULL,
  `content_id` int(11) NOT NULL AUTO_INCREMENT,
  `content` text COLLATE latin1_general_ci,
  `content_area` varchar(30) COLLATE latin1_general_ci DEFAULT NULL,
  `content_name` varchar(50) COLLATE latin1_general_ci DEFAULT NULL,
  PRIMARY KEY (`content_id`),
  KEY `page_id` (`page_id`),
  CONSTRAINT `page_id` FOREIGN KEY (`page_id`) REFERENCES `pages` (`pages_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_general_ci;

LOCK TABLES `content` WRITE;
/*!40000 ALTER TABLE `content` DISABLE KEYS */;

INSERT INTO `content` (`content_order`, `page_id`, `content_id`, `content`, `content_area`, `content_name`)
VALUES
	(0,38,3,'<h1>Header</h1>','header','H1'),
	(0,38,37,'<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</p><p><br></p><p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.<br></p><p><br></p><p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.<br></p>','content','Content'),
	(0,36,42,'<h1 class=\"fr-tag\">Refined Framework</h1><p class=\"fr-tag\">This is filler content, don\'t take it too seriously.</p><p class=\"fr-tag\"><a class=\"btn btn-primary btn-lg\" href=\"https://github.com/katerman/framework\">Github Â»</a></p>','jumbotron','content'),
	(0,36,43,'            <h2>Heading</h2>            <p>Donec sed odio dui. Cras justo odio, dapibus ac facilisis in, egestas eget quam. Vestibulum id ligula porta felis euismod semper. Fusce dapibus, tellus ac cursus commodo, tortor mauris condimentum nibh, ut fermentum massa justo sit amet risus.</p>            <p><a class=\"btn btn-default\" href=\"#\" role=\"button\">View details Â»</a></p>','column_one','column 1'),
	(0,36,44,'            <h2>Heading</h2>\n\n            <p>Donec sed odio dui. Cras justo odio, dapibus ac facilisis in, egestas eget quam. Vestibulum id ligula porta felis euismod semper. Fusce dapibus, tellus ac cursus commodo, tortor mauris condimentum nibh, ut fermentum massa justo sit amet risus.</p>\n\n            <p><a class=\"btn btn-default\" href=\"#\" role=\"button\">View details &raquo;</a></p>','column_two','column 2'),
	(0,36,45,'            <h2>Heading</h2>            <p>Donec sed odio dui. Cras justo odio, dapibus ac facilisis in, egestas eget quam. Vestibulum id ligula porta felis euismod semper. Fusce dapibus, tellus ac cursus commodo, tortor mauris condimentum nibh, ut fermentum massa justo sit amet risus.</p>            <p><a class=\"btn btn-default\" href=\"#\" role=\"button\">View details Â»</a></p>','column_three','column 3'),
	(0,51,46,'<h1>Header One</h1>','header_col_one','header_col_one'),
	(0,51,47,'<h2>Header Two</h2>','header_col_two','header_col_two'),
	(0,51,48,'<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.<br></p><p><br></p><p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.<br></p><p><br></p><p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.<br></p>','content_col_one','content_col_one'),
	(0,51,49,'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.<p><br></p><p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.<br></p><p><br></p><p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.<br></p>','content_col_two','content_col_two'),
	(10,52,50,'<h3>0.5 (Alpha)</h3><ul><li>Complete overhaul of file system.</li><li>changed token security system to be easier, and less stupid, stop looking for specific tokens every time and just look for âtokenâ.</li><li>created an app.php file to run all necessary classes.</li><li>fixed some issues with the logs index, and admins index (if no session make it null, no extra session_start()).</li><li>removed index.html from folders i didnât want people to access from the browser and replaced it with a proper .htaccess block</li><li>image upload checks for access level 1, just in case.. this will be updated in 0.6, however in the future where different users have different permissions it will most likely use the same concept. This implementation actually breaks image uploading, donât use 0.5 for image uploading.</li><li>updated several php starts to use php keyword </li><li>updated add page to check for parent page.</li><li>dashboard by user is now available, go into users view find a user and change their user comments, this will appear in their dashboard.</li><li>missed some quotes, added them in.</li><li>edit_page updates include checking for subpage and template correctly</li><li>edit user now says âedit user_fullnameâ.</li><li>footer in admin changed to be responsive</li><li>WYSIWYG added to user comments, and page content, this will make it much easier for users to quickly make edits they want.</li><li>AuthView is now appView, authModel is now appModel</li><li>appView checks for admin/log/site to pick specific folders, it also has a debug setting $tpl_debug in app_view.php</li><li>removed the old responsive table js in favor of a css based fix.</li><li>responsiveness for deleting should now be better, not perfect.</li><li>admin js function to check for external links and open them in a new window - hand in hand with dashboard, and another to check for query strings in url.</li><li>WYSIWYG will only run on ?type=edit_page and ?type=edit_user, check the JS to change this around.</li><li>updated getQuery() to check for isset correctly</li><li>php will throw errors on page, to help development, will be configurable in 0.6</li></ul>','','0.5'),
	(9,52,51,'<h3>0.6.3</h3><ul><li>image delete was broken, now fixed.</li></ul><h3>0.6.2</h3><ul><li>deleted unessicary things in delete_image.php, and when you delete an image its resized counter part is also unlinked.</li><li>edit_config.inc tons of changes to accomidate the image chooser</li><li>uploaded.inc now has the ability to rename an image (or other file). The js will only show the checkmark to accept a new name.</li><li>css for wysiwyg, overlay importances, image chooser, uploadeds pictures, rename stuff, added quotes around image urls</li><li>wysiwyg somewhat responsive.</li><li>added equalheight() incase i need it.</li><li>image chooser function</li><li>updated jquery.min.js</li><li>helpers php has a image resizer $helpers->smart_resize_image(opts);</li></ul><h3>0.6.1</h3><ul><li>more options in config, yay.</li><li>removed access check in upload.php</li><li>added favicon to admin, and changed title to use helpers::url(base)</li><li>updated labels token.</li><li>can now config if you want uploads (100% or 0%, no user permissions yet)</li><li>ajaxed out uploaded.inc</li><li>template debug is in config(true/false), error reporting is configable (true/false), timezone is configable string (\'America/New_York\')</li><li>updated demo sites footer using wrong $_config calls</li><li>css for ajaxed uploaded.inc to confirm delete</li><li>error reporting is configable,</li><li>delete image script in admin, for deleting images in uploads.</li></ul>','','0.6.x'),
	(8,52,52,'<h3>0.7.1</h3>\n<ul>\n	<li>Each individual template checks for permissions before displaying.</li>\n</ul>\n\n<h3>0.7.0</h3>\n<ul>\n	<li>User Permissions on a user by user basis, no user groups yet.</li>\n	<li>the mandetory css changes.</li>\n	<li>i think i fixed a x-scrollbar issue, hopefully.</li>\n	<li>user permissions for 0.7.0 are nav only, user could still travel to the page.</li>\n	<li>image check in uploaded before resizing, dont want to try to resize a non-image that throws an error.</li>\n	<li>added normalize.css to admin.</li>\n	<li>updated skeleton.css hopefully for the better.</li>\n</ul>','','0.7.x'),
	(7,52,53,'<h3>0.8.2</h3>\n<ul>\n	<li>added 404 page (non customizable, if the page url isnât in the db it will auto forward to 404, so you need a 404 page under pages).</li>\n	<li>fix in app/views/body.inc</li>\n	<li>fix in labels.inc</li>\n</ul>\n\n<h3>0.8.1</h3>\n<ul>\n	<li>Better and more thought out sanitization added to add/update. $helpers->custom_clean($passin,$js,$html, look in helpers for the whole list)</li>\n	<li>log is fixed, purge button added but not functional yet.</li>\n	<li>minor template fixes for admin</li>\n	<li>minor css fixes for admin</li>\n	<li>$helpers has an added sqlDelete() method that does not function yet.</li>\n</ul>\n\n<h3>0.8.0 (Beta)</h3>\n<ul>\n	<li>Upgraded from alpha to beta.</li>\n	<li>helper class now handles sqlSelect(). This involves helpers having its own PDO method.</li>\n	<li>New UI, tons of small changes to accomidate (JS/CSS/INC)</li>\n	<li>Font Awesome Added (not all symbols updated yet)</li>\n	<li>put in some docblocks in helpers</li>\n	<li>old css file saved, but will eventually be phazed out.</li>\n</ul>','','0.8.x'),
	(6,52,54,'\n\n<h3>0.9.0</h3>\n<ul>\n	<li>When creating a user, validation will now check to see if there is already a user with that username.</li>\n	<li>Username cannot be edited any longer.</li>\n	<li>log updates, you can now purge the log using helpers truncate method</li>\n	<li>added jquery.cookie.js this will help remmeber what state the nav should be in.</li>\n	<li>logo in config will now have the already selected logo set as its value. Now you dont have to reselect a new one everytime you save.</li>\n	<li>log will now show up under users, its still in its own subfolder and will be changed in the future to be contained in the admin where it should be</li>\n	<li>view class now has two new methods $view->show_content, and $view->show_label</li>\n	<li>bootstrap theme for the front end, making it look more presentable</li>\n	<li>css updates</li>\n</ul>','','0.9.x'),
	(5,52,55,'<h3>1.31</h3>\n<ul>\n<li>pager class edited. Pager class no longer requires an amount/page to function it will automatically take the start values, and only take parameters from links when they are present.</li>\n<li>new pager class method for hiding the pager system if there is no rows to be shown. setShowPagerWhereNoData() / getShowPagerWhereNoData()</li>\n<li>search page updated to have pagers.</li>\n<li>small misc changes to a few files/ taking out useless code.</li>\n<li>css for search pages pager</li>\n<li>responsive bug fixed</li>\n<li>js for pager updated</li>\n<li>pager added to app.php so it auto includes on all pages that require app.php</li>\n</ul>\n\n<h3>1.3</h3><ul><li> removed a few old code from index.php\'s</li><li> image information is now stored in DB, delete/rename/upload updated to hit file system and Db now.</li><li> search script, now admin has the ability to search through content/pages/templates/labels and users</li><li> html/css changes for the better.</li><li> some pages session data set up.</li><li> user session contains comments now.</li><li> basic php caching added in config, off by default.</li><li> updated dropzone/form.js</li><li> fun new classes, User.class and table.class</li><li> Helpers now has the rest of the CRUD functions sqlUpdate, sqlRaw (input your own statement) each sql method as a debugging option </li><li> script included to update all images in file system to database (update_images_db.php)</li><li> base sql file updated</li></ul><h3>1.2</h3><ul><li>log where updated to orderby ID (latest entry)</li><li>updating default.inc</li><li>new script to handle resized images on the fly \"img src=\"includes/scripts/image.php?w=1000&fit=0&h=120&file=refined.png\"\"</li></ul><h3>1.1</h3><ul><li>sql table added</li><li>docblock added to a helpers method</li><li>admin.js changed to accomidate more than one pager</li><li>added pager to log</li><li>two pagers on edit_page one for sub-pages and one for content</li><li>some fixes in pager.class.php</li><li>upon calling a new pager the pager class will generate some js for admin.js to grab. make sure page_key, and amt_key are never the same when using more than one pager.</li></ul><h3>1.0</h3><ul><li>scripts in admin are now in admin/scripts, it needed organization.</li><li>log is out of its own folder, and now correctly in admin under users.</li><li>pagenation class, and implimentation on several pages.</li><li>updated add_user.inc</li><li>updated the search inputs to say filter instead, because they dont search</li><li>trying to remove hashs from links.</li><li>css fixes to admin</li><li>removed old css</li><li>admin_ajax has a pager function to go with php pager class</li><li>$helpers->setParam will force page redirect even after headers have sent.</li></ul>','','1.x'),
	(4,52,58,'<h3>1.32</h3><ul>\n<li> Upgrade system now in place, it will check if an update is avaliable and install it.\n</li><li> New scattershot area under assets. Scattershot will be for any information to be quickly added to the db. That can later be used for any number of purposes. \n</li><li> couple new config options config path and root path, and a upgrade remote path.\n</li><li> add/upgrade.php were upgraded to use newer helper methods.\n</li><li> start of form class is included, not suggested to use it yet.\n</li><li> minor fixes to many template files\n</li><li> new css, and css fixes</li></ul>\n','','1.32'),
	(0,36,59,'<p class=\"fr-tag\">test 2</p>','','test');

/*!40000 ALTER TABLE `content` ENABLE KEYS */;
UNLOCK TABLES;


# Dump of table images
# ------------------------------------------------------------

CREATE TABLE `images` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `image_name` tinytext NOT NULL,
  `image_desc` text NOT NULL,
  `image_created` datetime NOT NULL,
  `image_size` tinytext,
  `image_type` tinytext,
  `uploaded_by` tinytext,
  `last_edited_by` tinytext,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;



# Dump of table labels
# ------------------------------------------------------------

CREATE TABLE `labels` (
  `label_id` int(11) NOT NULL AUTO_INCREMENT,
  `label_content` varchar(300) COLLATE latin1_general_ci NOT NULL,
  `label_name` varchar(50) COLLATE latin1_general_ci DEFAULT NULL,
  PRIMARY KEY (`label_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_general_ci;

LOCK TABLES `labels` WRITE;
/*!40000 ALTER TABLE `labels` DISABLE KEYS */;

INSERT INTO `labels` (`label_id`, `label_content`, `label_name`)
VALUES
	(15,'Refined Designs &copy;','refined_designs'),
	(16,'testa','atest');

/*!40000 ALTER TABLE `labels` ENABLE KEYS */;
UNLOCK TABLES;


# Dump of table log
# ------------------------------------------------------------

CREATE TABLE `log` (
  `log_id` int(10) NOT NULL AUTO_INCREMENT,
  `log_name` varchar(25) NOT NULL,
  `log_action` varchar(25) NOT NULL,
  `log_content` text NOT NULL,
  `log_time` varchar(45) NOT NULL,
  PRIMARY KEY (`log_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;



# Dump of table pages
# ------------------------------------------------------------

CREATE TABLE `pages` (
  `on_nav` int(11) NOT NULL DEFAULT '0',
  `parent_page` int(5) DEFAULT NULL,
  `pages_id` int(11) NOT NULL AUTO_INCREMENT,
  `page_name` varchar(30) COLLATE latin1_general_ci DEFAULT NULL,
  `page_template` varchar(40) COLLATE latin1_general_ci DEFAULT NULL,
  `page_group` varchar(20) COLLATE latin1_general_ci DEFAULT NULL,
  `sub_page` varchar(10) COLLATE latin1_general_ci DEFAULT 'none',
  `page_meta_keyword` varchar(100) COLLATE latin1_general_ci DEFAULT NULL,
  `page_meta_title` varchar(50) COLLATE latin1_general_ci DEFAULT NULL,
  `page_url` varchar(15) COLLATE latin1_general_ci DEFAULT NULL,
  `page_order` int(3) DEFAULT NULL,
  PRIMARY KEY (`pages_id`),
  UNIQUE KEY `pages_id` (`pages_id`),
  KEY `pages_id_2` (`pages_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_general_ci;

LOCK TABLES `pages` WRITE;
/*!40000 ALTER TABLE `pages` DISABLE KEYS */;

INSERT INTO `pages` (`on_nav`, `parent_page`, `pages_id`, `page_name`, `page_template`, `page_group`, `sub_page`, `page_meta_keyword`, `page_meta_title`, `page_url`, `page_order`)
VALUES
	(1,0,36,'home','15','','none','homepage, more stuff, more more more stuff','the homepage is where the heart is','home',1),
	(1,0,38,'about','19','','none','about, page, doodley','the about page is where learn about stuff','about',2),
	(1,NULL,51,'twocol','21','','none','','','twocol',3),
	(1,NULL,52,'Update Log','19','','none','','','update_log',4);

/*!40000 ALTER TABLE `pages` ENABLE KEYS */;
UNLOCK TABLES;


# Dump of table scattershot
# ------------------------------------------------------------

CREATE TABLE `scattershot` (
  `scattershot_id` int(11) NOT NULL AUTO_INCREMENT,
  `value` text COLLATE latin1_general_ci,
  `name` text COLLATE latin1_general_ci,
  `type` text COLLATE latin1_general_ci,
  `anchor` text COLLATE latin1_general_ci,
  `class` text COLLATE latin1_general_ci,
  `id` text COLLATE latin1_general_ci,
  PRIMARY KEY (`scattershot_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_general_ci;



# Dump of table templates
# ------------------------------------------------------------

CREATE TABLE `templates` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `template_type` int(2) NOT NULL,
  `template_name` varchar(25) COLLATE latin1_general_ci DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_general_ci;

LOCK TABLES `templates` WRITE;
/*!40000 ALTER TABLE `templates` DISABLE KEYS */;

INSERT INTO `templates` (`id`, `template_type`, `template_name`)
VALUES
	(15,0,'home'),
	(19,0,'default'),
	(21,0,'twocol');

/*!40000 ALTER TABLE `templates` ENABLE KEYS */;
UNLOCK TABLES;


# Dump of table users
# ------------------------------------------------------------

CREATE TABLE `users` (
  `users_Id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `user_uName` varchar(20) NOT NULL DEFAULT '',
  `user_Pass` varchar(128) NOT NULL DEFAULT '',
  `user_FullName` text NOT NULL,
  `user_Salt` varchar(8) DEFAULT NULL,
  `user_Access` int(1) DEFAULT NULL,
  `user_Comments` text,
  `user_custom_perms` text NOT NULL,
  PRIMARY KEY (`users_Id`),
  UNIQUE KEY `UX_name` (`user_uName`),
  UNIQUE KEY `UX_name_password` (`user_Pass`,`user_uName`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;




/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
