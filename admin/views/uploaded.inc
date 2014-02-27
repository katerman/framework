<?php
include_once "../includes/scripts/app.php";

$security = new security();

$token = $security->generateFormToken('token'); 

?>
<h1> Things we've uploaded! </h1>

<div id="uploaded">
<p class="results"></p>
<p class="hidden" id="token"><?php echo $token ?></p>
	<ul>
		<?php
		
		$dirname = "../uploads/";
		$images = glob("{$dirname}*.*");
		
		if($images){
		foreach($images as $k=>$image) {
			echo '<li><p>'. str_replace('../uploads/', '', $image) .'</p><img class="uploaded" src="'.$image.'" />';
			echo '<form method="post" class="image-'.$k.'">';
			echo '<input class="image_value" type="hidden" value="'.$image.'" name="delete_file" />';
			echo '<div class="picture_box"><input type="submit" value="Delete image" class="delete_btn"/></div>';
			echo '</form></li>';
		}
		}
		
		?>
	</ul>
</div>