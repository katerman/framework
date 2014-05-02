<? 
	global $model; 
	global $helpers; 
	global $view;
	global $security;
	global $_CONFIG;
	
	$page_url = $helpers->getQuery('page','return');
	$q = $helpers->sqlSelect("*" , "pages", "", "WHERE page_url LIKE '%$page_url%'");
	$c = $helpers->sqlSelect("*" , "config", "", "");
	$l = $helpers->sqlSelect("*" , "labels", "", "");
	
	if(empty($q)){
		header("HTTP/1.0 404 Not Found");
		header("Location: /page/404");
	}

	$GLOBALS['config'] = $c[0];
	$GLOBALS['page'] = $q[0];
	
	$page = $GLOBALS['page']; 
	$config = $GLOBALS['config'];
	
	$page_id = $page['pages_id'];
	$cont = $helpers->sqlSelect("*" , "content", "", "WHERE page_id = $page_id");
	
	$GLOBALS['content'] = $cont;
	$content = $GLOBALS['content'];
	
	//areas
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
	
	
	//labels
	$labels = new stdClass;
	
	foreach($l as $lab){
		$labels->$lab['label_name'] = $lab['label_content'];
	}
	
	$GLOBALS['labels'] = $labels;
	$labels = $GLOBALS['labels'];
	

	
	//print_r($_CONFIG);

?> 
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8"/>
	<link rel="stylesheet" href="<?php echo $_CONFIG->css_path; ?>global.css" type="text/css" media="screen">
	<style>
		<?php echo $config['extra_css']; ?>
	</style>
	<title><?php echo $page['page_name']; ?></title>
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