<?php
$path = dirname(__FILE__);

require_once $path."/../../_config.php";

if($_CONFIG->error_reporting){
	error_reporting(E_ALL);
	ini_set('display_errors', 1);
}

if($_CONFIG->caching === false){
	header("Cache-Control: no-store, no-cache, must-revalidate, max-age=0");
	header("Cache-Control: post-check=0, pre-check=0", false);
	header("Pragma: no-cache");
}

date_default_timezone_set($_CONFIG->date_default_timezone_set);

if(!isset($_SESSION)) { session_start(); }

require_once $path."/../../_config.php";
require_once $path."/../../app/db.php";
require_once $path."/../../app/app_model.php";
require_once $path."/../../app/app_view.php";
require_once $path."/helpers.php";
require_once $path."/security.php";
require_once $path."/user.class.php";
require_once $path."/strings.php";
require_once $path."/table.class.php";