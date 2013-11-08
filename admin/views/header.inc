<? 
	global $model; 
	global $helpers; 
	global $view;
	global $security;

	
?>

<div id="header">
	<? echo '<h1>'. ucfirst($helpers::url(base)).' Admin Panel</h1>'; ?>
	<a class="logout" href="logout.php">Log out</a>

</div>