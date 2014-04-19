<?php
$dsn = "mysql:host=127.0.0.1;port=3306;dbname=refinee9_refined_db";

$db_user= "refinee9_admin";

$db_pass = "halo12";

try
{
	$db = new PDO($dsn, $db_user, $db_pass);
}
catch(PDOException $e)
{
    die("Failed to connect to the database: " . $e->getMessage());
}

$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
$db->setAttribute(PDO::ATTR_DEFAULT_FETCH_MODE, PDO::FETCH_ASSOC);