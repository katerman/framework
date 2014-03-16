<?php
	if($perms['assets']['upload'] == 1 && $perms['assets']['top_level'] == 1){
?>

<?php
	global $_CONFIG;

	if($_CONFIG->allow_image_upload){
	
?>

<h1> Upload someting matey? </h1>

<form action="upload.php" class="dropzone"></form>

<script src="<? echo $_CONFIG->js_path; ?>dropzone.min.js" charset="utf-8"></script>

<?php
	}else{
		echo '<h1>Sorry, you don\'t have image uploads enabled';
	}
?>

<?php
	}else{
		header('Location: ?tpl=default_view#dashboard');
	}
?> 	
