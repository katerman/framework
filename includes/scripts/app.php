<?php
$path = dirname(__FILE__);

require_once $path."/../../_config.php";

if($_CONFIG->error_reporting){
	error_reporting(E_ALL);
	ini_set('display_errors', 1);
}

date_default_timezone_set($_CONFIG->date_default_timezone_set);

if(!isset($_SESSION)) { session_start(); }

require_once $path."/../../_config.php";
require_once $path."/../../app/db.php";
require_once $path."/../../app/app_model.php";
require_once $path."/../../app/app_view.php";
require_once $path."/helpers.php";
require_once $path."/security.php";
