<?php
	if($perms['assets']['uploaded'] == 1 && $perms['assets']['top_level'] == 1){
?>

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
		
		function is_image($path){
		    $a = getimagesize($path);
		    $image_type = $a[2]; //$a[0] and $a[1] are the width and height of the image. $a[2] has the image type.
		     
		    if(in_array($image_type , array(IMAGETYPE_GIF , IMAGETYPE_JPEG ,IMAGETYPE_PNG , IMAGETYPE_BMP))){
		        return true;
		    }
		    return false;
		}
		
		$dirname = "../uploads/";
		$images = glob("{$dirname}*.*");
		
		if($images){
			foreach($images as $k=>$image){
			
				$image = str_replace('../uploads/', '', $image);
				$image_name = $image;
				
				$i = '../uploads/resized/'.$image_name.'-resized';
				if(!file_exists($i) && is_image('../uploads/'.$image_name)){
					$helpers->smart_resize_image('../uploads/'.$image_name , 164 , 111 , true , $i , false , false ,80 );//file, width, height, proportional, output, delete org, use linux commands, quality
				}
				
				echo '<li class="rename_li">
					<form class="image_rename-'.$k.'" placeholder="Name of Image">
						<input type="text" class="new_name" name="new_name" value="'. str_replace('../uploads/', '', $image) .'">
						<input type="hidden" class="old_name hidden" name="old_name" value="'. str_replace('../uploads/', '', $image) .'">
						</input><button class="rename">&#x2713;</button>
					</form>'
				;
				
				if (file_exists($i)){
					echo '<img class="uploaded" src="'.$i.'" />';
				}else{
					echo '<div class="no_preview"><p>Sorry, No preview</p></div>';
				}
				 echo '<form method="post" class="image-'.$k.'">'
				 .'<input class="image_value" type="hidden" value="'.$image.'" name="delete_file" />'
				 .'<div class="picture_box"><input type="submit" value="Delete" class="delete_btn"/></div>'
				 .'</form></li>';
			}
		}
		
		?>
	</ul>
</div>

<?php
	}else{
		header('Location: ?tpl=default_view#dashboard');
	}
?> 	
