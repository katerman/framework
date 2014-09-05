<?php
$dsn = "mysql:host=127.0.0.1;port=3306;dbname=DBNAME";

$db_user= "USERNAME";

$db_pass = "PASSWORD";

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