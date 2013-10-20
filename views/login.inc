<div id="content">
	<h1>General Site</h1>
	
	<p>Please, Log in.</p>
	
	<form action="?" method="POST">
	
	<label for="username">Username:</label>
	
		<input type="text" name="username" id="username" maxlength="20" size="20"/><br/>
	
		
	<label for="password">Password:</label>
	
		<input type="password" name="password" id="password" maxlength="20" size="20"/><br/>
		
	<input type="submit"/>
	
	</form>
	
	<h1><? echo helpers::url(base); ?></h1>
	<p>Welcome back, <?php if($data['fullname']){echo htmlentities($data['fullname']);}else{echo 'guest';}?>.</p>
	<?php if($data){echo '<p><a class="logout" href="logout.php">Log out</a></p>';} ?>

</div>

<?php
	echo 'full: ' . helpers::url(full) . '<br>';
	echo 'fullpage: ' . helpers::url(fullpage) . '<br>';
	echo 'folder: ' . helpers::url(folder) . '<br>';
	echo 'base: ' . helpers::url(base) . '<br>';
	echo 'lastpath: ' . helpers::url(lastpath);

?>
