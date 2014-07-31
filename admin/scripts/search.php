<?php

	global $dsn, $db_user, $db_pass;
		
	include_once "../includes/scripts/app.php";
	include_once "scripts/pager.class.php";

	$helpers = new helpers($dsn, $db_user, $db_pass);
	$security = new security();
	
	$token = $security->generateFormToken('token'); 
	$query = $helpers->custom_clean($_GET['search']);
		
	$content = $helpers->sqlSelect("*", "content", false, "WHERE content LIKE '%$query%' OR content_area LIKE '%$query%' OR content_name LIKE '%$query%'");
	$users   = $helpers->sqlSelect("users_Id, user_uName, user_FullName, user_Comments", "users", false, "WHERE user_uName LIKE '%$query%' OR user_FullName LIKE '%$query%' OR user_Comments LIKE '%$query%'");
	$labels  = $helpers->sqlSelect("*", "labels", false, "WHERE label_content LIKE '%$query%' OR label_name LIKE '%$query%'");
	$templates  = $helpers->sqlSelect("*", "templates", false, "WHERE template_name LIKE '%$query%' OR template_name LIKE '%$query%'");
	$pages  = $helpers->sqlSelect("*", "pages", false, "WHERE page_name LIKE '%$query%' OR page_group LIKE '%$query%' OR page_template LIKE '%$query%' OR page_meta_keyword LIKE '%$query%' OR page_meta_title LIKE '%$query%'");
	
	
	