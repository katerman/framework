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
	$cont = $model->sqlSelect("*" , "content", "", "WHERE page_id = $page_id");
	
	$GLOBALS['content'] = $cont;
	$content = $GLOBALS['content'];
	
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
	
	//print_r($content);

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