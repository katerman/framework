<? 
	global $model; 
	global $helpers; 
	global $view;
	global $security;
	
	
	$page_url = $helpers->getQuery('page','return');
	$q = $model->sqlSelect("*" , "pages", "", "WHERE page_url LIKE '%$page_url%'");
	$c = $model->sqlSelect("*" , "config", "", "");

	$GLOBALS['config'] = $c[0];
	$GLOBALS['page'] = $q[0];
	
	$page = $GLOBALS['page']; 
	$config = $GLOBALS['config'];
	
	$page_id = $page['pages_id'];
	$content = $model->sqlSelect("*" , "content", "", "WHERE page_id = $page_id");
	
	$areas = new stdClass;
	
	foreach($content as $con){
		$areas->$con['content_area'] = $con['content'];
	}
	
	$GLOBALS['areas'] = $areas;
	$areas = $GLOBALS['areas'];
	 
	print_r($areas);

?> 
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8"/>
	<link rel="stylesheet" href="css/global.css" type="text/css" media="screen">
	<style>
		<? echo $config['extra_css']; ?>
	</style>
	<title><? echo $page['page_name']; ?></title>
	<meta name="description" content="<? echo $page['page_meta_title']; ?>"> 
	<meta name="ROBOTS" content="INDEX, FOLLOW">
	<meta name="keywords" content="<? echo $page['page_meta_keyword']; ?>"> <!-- only used by bing -->
	<meta http-equiv="content-type" content="text/html;charset=UTF-8">
</head>
<body>

  <? 
	  //print_r($page);
	 //print_r($config);
	//print_r($content);  
	  
  ?>