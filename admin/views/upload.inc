<?php

if($perms['assets']['upload'] == 1 && $perms['assets']['top_level'] == 1){

	global $_CONFIG;
	global $security;

	if($_CONFIG->allow_image_upload){
	
		$token = $security->generateFormToken('token'); 
		//echo $token;
		//print_r($_SESSION);
	
?>

<h1> Upload</h1>
<p>Drag a file onto the area below to automatically upload that file. Alternatively you can click on the area below to do the same thing.</p>

<form action="scripts/upload.php" id="dropzone" class="dropzone" enctype="multipart/form-data">
	<input type="hidden" class="token" name="token" value="<?php echo $token; ?>">	
</form>

<?php

	}else{
		echo '<h1>Sorry, you don\'t have image uploads enabled';
	}

}else{
	header('Location: ?tpl=default_view');
}

?> 	
