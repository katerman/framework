<?php

error_reporting(E_ALL);
ini_set('display_errors', 1);

$path = dirname(__FILE__);

date_default_timezone_set('America/New_York');

require_once $path."/../../app/db.php";
require_once $path."/../../app/app_model.php";
require_once $path."/../../app/app_view.php";
require_once $path."/helpers.php";
require_once $path."/security.php";
require_once $path."/../../_config.php";