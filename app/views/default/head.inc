<?php
	global $page, $config, $_CONFIG;
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8"/>

	<!-- Latest compiled and minified CSS -->
	<link rel="stylesheet" href="//netdna.bootstrapcdn.com/bootstrap/3.1.1/css/bootstrap.min.css">
	<!-- Optional theme -->
	<link rel="stylesheet" href="//netdna.bootstrapcdn.com/bootstrap/3.1.1/css/bootstrap-theme.min.css">

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
