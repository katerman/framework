<?php

	global $dsn, $db_user, $db_pass;
		
	include_once "../includes/scripts/app.php";

	$helpers = new helpers();
	$security = new security();
	
	$token = $security->generateFormToken('token'); 
	$query = $helpers->custom_clean($_GET['search']);	
	
	//content
	$content_amt = $helpers->getQuery('cntamt','return');	
	$content = new pager($content_amt, 'content', '*', 'cntamt', 'cntpage');  
	$content->setTableSqlDataWhere("WHERE content LIKE '%$query%' OR content_area LIKE '%$query%' OR content_name LIKE '%$query%'");
	$content->setShowPagerWhereNoData(true);
	
	//users
	$user_amt = $helpers->getQuery('usramt','return');		
	$users = new pager($user_amt, 'users', 'users_Id, user_uName, user_FullName, user_Comments', 'usramt', 'usrpage');  
	$users->setTableSqlDataWhere("WHERE user_uName LIKE '%$query%' OR user_FullName LIKE '%$query%' OR user_Comments LIKE '%$query%'");
	$users->setShowPagerWhereNoData(true);

	//labels
	$labels_amt = $helpers->getQuery('lblamt','return');		
	$labels = new pager($labels_amt, 'labels', '*', 'lblamt', 'lblpage');  
	$labels->setTableSqlDataWhere("WHERE label_content LIKE '%$query%' OR label_name LIKE '%$query%'");
	$labels->setShowPagerWhereNoData(true);

	//templates	
	$templates_amt = $helpers->getQuery('tplamt','return');		
	$templates = new pager($templates_amt, 'templates', '*', 'tplamt', 'tplpage');  
	$templates->setTableSqlDataWhere("WHERE template_name LIKE '%$query%' OR template_name LIKE '%$query%'");
	$templates->setShowPagerWhereNoData(true);

	//pages 	
	$pages_amt = $helpers->getQuery('tplamt','return');		
	$pages = new pager($pages_amt, 'pages', '*', 'pgamt', 'pgpage');  
	$pages->setTableSqlDataWhere("WHERE page_name LIKE '%$query%' OR page_group LIKE '%$query%' OR page_template LIKE '%$query%' OR page_meta_keyword LIKE '%$query%' OR page_meta_title LIKE '%$query%'");
	$pages->setShowPagerWhereNoData(true);
