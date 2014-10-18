<?php
	global $_CONFIG;
	global $helpers;
	
	$_SESSION['page'] = array();
	
	if(isset($_GET['pagename'])){
		$page['page_name'] = $_GET['pagename'];	
	}
	
	if(isset($_GET['tpl'])){
		$page['page_tpl'] = $_GET['tpl'];	
	}	

	$page = $_SESSION['page'];
		
?>

<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"/>
<meta name="viewport" content="width=device-width, initial-scale=1">
<meta http-equiv="X-UA-Compatible" content="IE=edge">

<link rel="icon" type="image/x-icon" href="<?php echo $_CONFIG->img_path;?>favicon.ico" />

<!-- CSS -->
<link rel="stylesheet" href="<?php echo $_CONFIG->css_path; ?>admin/global.css" type="text/css" media="screen" charset="utf-8">
<link rel="stylesheet" href="<?php echo $_CONFIG->css_path; ?>admin/dropzone.css" type="text/css" media="screen" charset="utf-8">
<link rel="stylesheet" href="<?php echo $_CONFIG->css_path; ?>admin/skeleton/skeleton.css" type="text/css" media="screen" charset="utf-8">
<link rel="stylesheet" href="<?php echo $_CONFIG->css_path; ?>admin/skeleton/layout.css" type="text/css" media="screen" charset="utf-8">

<link rel="stylesheet" href="<?php echo $_CONFIG->css_path; ?>admin/froala_page.min.css" type="text/css" media="screen" charset="utf-8">
<link rel="stylesheet" href="<?php echo $_CONFIG->css_path; ?>admin/froala_editor.min.css" type="text/css" media="screen" charset="utf-8">

<!-- Google fonts -->
<link href='http://fonts.googleapis.com/css?family=Oswald' rel='stylesheet' type='text/css'>
<link href='http://fonts.googleapis.com/css?family=Open+Sans' rel='stylesheet' type='text/css'>
<title>Admin-<?php echo $helpers->url('base'); ?></title>
</head>
<body>

<script>
	var pager_array = [];
</script>