-- phpMyAdmin SQL Dump
-- version 3.5.8.2
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: May 21, 2014 at 08:41 AM
-- Server version: 5.5.37-log
-- PHP Version: 5.4.23

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `REFINED_DB`
--

-- --------------------------------------------------------

--
-- Table structure for table `config`
--

DROP TABLE IF EXISTS `config`;
CREATE TABLE IF NOT EXISTS `config` (
  `site_name` varchar(50) COLLATE latin1_general_ci NOT NULL,
  `global_logo` varchar(100) COLLATE latin1_general_ci NOT NULL,
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `extra_js` varchar(1000) COLLATE latin1_general_ci DEFAULT NULL,
  `extra_css` varchar(1000) COLLATE latin1_general_ci DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_general_ci AUTO_INCREMENT=2 ;

--
-- Dumping data for table `config`
--

INSERT INTO `config` (`site_name`, `global_logo`, `id`, `extra_js`, `extra_css`) VALUES
('Framework Site', 'refined.png', 1, '', '');

-- --------------------------------------------------------

--
-- Table structure for table `content`
--

DROP TABLE IF EXISTS `content`;
CREATE TABLE IF NOT EXISTS `content` (
  `content_order` int(3) NOT NULL,
  `page_id` int(11) NOT NULL,
  `content_id` int(11) NOT NULL AUTO_INCREMENT,
  `content` text COLLATE latin1_general_ci,
  `content_area` varchar(30) COLLATE latin1_general_ci DEFAULT NULL,
  `content_name` varchar(50) COLLATE latin1_general_ci DEFAULT NULL,
  PRIMARY KEY (`content_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_general_ci AUTO_INCREMENT=50 ;

--
-- Dumping data for table `content`
--

INSERT INTO `content` (`content_order`, `page_id`, `content_id`, `content`, `content_area`, `content_name`) VALUES
(0, 38, 3, '<h1>Header</h1>', 'header', 'H1'),
(0, 38, 37, '<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.</p><p><br></p><p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.<br></p><p><br></p><p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.<br></p>', 'content', 'Content'),
(0, 36, 42, '<h1>Refined Framework</h1><p>This is filler content, don''t take it too seriously.</p><p><a href="https://github.com/katerman/framework" class="btn btn-primary btn-lg" role="button">Github Â»</a></p>', 'jumbotron', 'content'),
(0, 36, 43, '            <h2>Heading</h2>            <p>Donec sed odio dui. Cras justo odio, dapibus ac facilisis in, egestas eget quam. Vestibulum id ligula porta felis euismod semper. Fusce dapibus, tellus ac cursus commodo, tortor mauris condimentum nibh, ut fermentum massa justo sit amet risus.</p>            <p><a class="btn btn-default" href="#" role="button">View details Â»</a></p>', 'column_one', 'column 1'),
(0, 36, 44, '            <h2>Heading</h2>\n\n            <p>Donec sed odio dui. Cras justo odio, dapibus ac facilisis in, egestas eget quam. Vestibulum id ligula porta felis euismod semper. Fusce dapibus, tellus ac cursus commodo, tortor mauris condimentum nibh, ut fermentum massa justo sit amet risus.</p>\n\n            <p><a class="btn btn-default" href="#" role="button">View details &raquo;</a></p>', 'column_two', 'column 2'),
(0, 36, 45, '            <h2>Heading</h2>            <p>Donec sed odio dui. Cras justo odio, dapibus ac facilisis in, egestas eget quam. Vestibulum id ligula porta felis euismod semper. Fusce dapibus, tellus ac cursus commodo, tortor mauris condimentum nibh, ut fermentum massa justo sit amet risus.</p>            <p><a class="btn btn-default" href="#" role="button">View details Â»</a></p>', 'column_three', 'column 3'),
(0, 51, 46, '<h1>Header One</h1>', 'header_col_one', 'header_col_one'),
(0, 51, 47, '<h2>Header Two</h2>', 'header_col_two', 'header_col_two'),
(0, 51, 48, '<p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.<br></p><p><br></p><p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.<br></p><p><br></p><p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.<br></p>', 'content_col_one', 'content_col_one'),
(0, 51, 49, 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.<p><br></p><p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.<br></p><p><br></p><p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.<br></p>', 'content_col_two', 'content_col_two');

-- --------------------------------------------------------

--
-- Table structure for table `labels`
--

DROP TABLE IF EXISTS `labels`;
CREATE TABLE IF NOT EXISTS `labels` (
  `label_id` int(11) NOT NULL AUTO_INCREMENT,
  `label_content` varchar(300) COLLATE latin1_general_ci NOT NULL,
  `label_name` varchar(50) COLLATE latin1_general_ci DEFAULT NULL,
  PRIMARY KEY (`label_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_general_ci AUTO_INCREMENT=17 ;

--
-- Dumping data for table `labels`
--

INSERT INTO `labels` (`label_id`, `label_content`, `label_name`) VALUES
(15, 'Refined Designs &copy;', 'refined_designs');

-- --------------------------------------------------------

--
-- Table structure for table `log`
--

DROP TABLE IF EXISTS `log`;
CREATE TABLE IF NOT EXISTS `log` (
  `log_id` int(10) NOT NULL AUTO_INCREMENT,
  `log_name` varchar(25) NOT NULL,
  `log_action` varchar(25) NOT NULL,
  `log_content` text NOT NULL,
  `log_time` varchar(45) NOT NULL,
  PRIMARY KEY (`log_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=16 ;

-- --------------------------------------------------------

--
-- Table structure for table `pages`
--

DROP TABLE IF EXISTS `pages`;
CREATE TABLE IF NOT EXISTS `pages` (
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
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_general_ci AUTO_INCREMENT=53 ;

--
-- Dumping data for table `pages`
--

INSERT INTO `pages` (`on_nav`, `parent_page`, `pages_id`, `page_name`, `page_template`, `page_group`, `sub_page`, `page_meta_keyword`, `page_meta_title`, `page_url`, `page_order`) VALUES
(1, 0, 36, 'home', '15', '', 'none', 'homepage, more stuff, more more more stuff', 'the homepage is where the heart is', 'home', 1),
(1, 0, 38, 'about', '19', '', 'none', 'about, page, doodley', 'the about page is where learn about stuff', 'about', 2),
(1, NULL, 51, 'twocol', '21', '', 'none', '', '', 'twocol', 3);

-- --------------------------------------------------------

--
-- Table structure for table `templates`
--

DROP TABLE IF EXISTS `templates`;
CREATE TABLE IF NOT EXISTS `templates` (
  `template_type` int(2) NOT NULL,
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `template_name` varchar(25) COLLATE latin1_general_ci DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COLLATE=latin1_general_ci AUTO_INCREMENT=23 ;

--
-- Dumping data for table `templates`
--

INSERT INTO `templates` (`template_type`, `id`, `template_name`) VALUES
(0, 15, 'home'),
(0, 19, 'default'),
(0, 21, 'twocol');

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
CREATE TABLE IF NOT EXISTS `users` (
  `users_Id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `user_uName` varchar(20) NOT NULL DEFAULT '',
  `user_Pass` char(32) NOT NULL DEFAULT '',
  `user_FullName` varchar(40) NOT NULL DEFAULT '',
  `user_Salt` char(8) DEFAULT NULL,
  `user_Access` int(1) DEFAULT NULL,
  `user_Comments` text,
  `user_custom_perms` text NOT NULL,
  PRIMARY KEY (`users_Id`),
  UNIQUE KEY `UX_name` (`user_uName`),
  UNIQUE KEY `UX_name_password` (`user_Pass`,`user_uName`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=42 ;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`users_Id`, `user_uName`, `user_Pass`, `user_FullName`, `user_Salt`, `user_Access`, `user_Comments`, `user_custom_perms`) VALUES
(34, 'admin', '1bf7a4d56591dfe62d1545e0997cdf52', 'Test Admin', '12898661', 1, NULL, ''),

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
