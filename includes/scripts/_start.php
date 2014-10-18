<?php

	//sets up global variables for frontward facing website/app

	//get page name
	$page_url = $helpers->getQuery('page','return');

	//sql queries
	$q = $helpers->sqlSelect("*" , "pages", "", "WHERE page_url LIKE '%$page_url%'");
	$c = $helpers->sqlSelect("*" , "config", "", "");
	$l = $helpers->sqlSelect("*" , "labels", "", "");

	//if no results return from the page name redirect them to 404 page (needs to be a page made in admin side)
	if(empty($q)){
		header("HTTP/1.0 404 Not Found");
		header("Location: /page/404");
		exit();
	}

	//globals for config (db) and page information
	$GLOBALS['config'] = $c[0];
	$GLOBALS['page'] = $q[0];

	$page = $GLOBALS['page'];
	$config = $GLOBALS['config'];

	$page_id = $page['pages_id'];

	//global for content information (for current page)
	$cont = $helpers->sqlSelect("*" , "content", "", "WHERE page_id = $page_id ORDER BY content_order ASC");
	$GLOBALS['content'] = $cont;
	$content = $GLOBALS['content'];

	//area information
	$areas = new stdClass;

	foreach($cont as $con){
		if($con['content_area']){
			$areas->$con['content_area'] = $con['content'];
		}else{
			$areas->$con['content_name'] = $con['content'];
		}
	}

	$GLOBALS['areas'] = $areas;
	$areas = $GLOBALS['areas'];


	//label information
	$labels = new stdClass;

	foreach($l as $lab){
		$labels->$lab['label_name'] = $lab['label_content'];
	}

	$GLOBALS['labels'] = $labels;
	$labels = $GLOBALS['labels'];