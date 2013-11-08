

<h1> Things we've uploaded! </h1>

<?
if (array_key_exists('delete_file', $_POST)) {
  $filename = $_POST['delete_file'];
  if (file_exists($filename)) {
    unlink($filename);
    echo '<p style="color: rgb(206, 36, 36); margin-bottom: 10px;">File '.$filename.' has been deleted</p>';
  } else {
    echo '<p style="color: rgb(206, 36, 36); margin-bottom: 10px;">Could not delete '.$filename.', file does not exist</p>';
  }
}

?>

<div id="uploaded">
	<ul>
		<?php
		
		$dirname = "../uploads/";
		$images = glob("{$dirname}*.*");
		
		if($images){
		foreach($images as $image) {
			echo '<li><p>'. str_replace('../uploads/', '', $image) .'</p><img class="uploaded" src="'.$image.'" />';
			echo '<form method="post">';
			echo '<input type="hidden" value="'.$image.'" name="delete_file" />';
			echo '<div class="picture_box"><input type="submit" value="Delete image" class="delete_btn"/></div>';
			echo '</form></li>';
		}
		}
		
		?>
	</ul>
</div>