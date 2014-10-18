<?php
	$user = new user();	
	$helpers = new helpers();
?>

<p>Welcome back, <?php echo $helpers->custom_clean($user->get_FullName());?>.</p>

<div class="dashboard">
<?php	
	echo $helpers->custom_clean($user->get_Comments()); 
?>
</div>
