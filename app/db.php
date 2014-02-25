<?php
$dsn = "mysql:host=127.0.0.1;port=3306;dbname=refinee9_refined_db";

$db_user= "refinee9_admin";

$db_pass = "halo12";

$db = new PDO($dsn, $db_user, $db_pass);
