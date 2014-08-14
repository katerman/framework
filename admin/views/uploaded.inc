<?php

if($perms['assets']['uploaded'] == 1 && $perms['assets']['top_level'] == 1){
	
	global $_CONFIG;
		
	$security = new security();
	
	$token = $security->generateFormToken('token'); 

	$amt = $helpers->getQuery('amt','return');
	$pager = new pager($amt, 'images', '*', 'atm', 'test');  

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
		$images = $helpers->sqlSelect("image_name, id", "images", false, "");
		//print_r($images);
		
		if($images){
			foreach($pager->getTableData() as $k=>$image){
				
				$image_name = $image['image_name'];
				$image_and_dir = $dirname.$image_name;

								
				if(file_exists($image_and_dir)){
				
					$id = $image['id'];
									
					$i = '../uploads/resized/'.$image_name.'-resized';
					if(!file_exists($i) && is_image('../uploads/'.$image_name)){
						$helpers->smart_resize_image('../uploads/'.$image_name , 164 , 111 , true , $i , false , false ,80 );//file, width, height, proportional, output, delete org, use linux commands, quality
					}
					
					echo '<li class="rename_li" id="image-'.$id.'">
						<form class="image_rename-'.$id.'" placeholder="Name of Image">
							<input type="text" class="new_name" name="new_name" value="'. $image_name .'">
							<input type="hidden" class="old_name hidden" name="old_name" value="'. $image_name .'">
							<input type="hidden" value="'.$id.'" name="image_id">
							</input><button class="rename">&#x2713;</button>
						</form>'
					;
					
					if (file_exists($i)){
						echo '<img class="uploaded" src="'.$i.'" />';
					}else{
						echo '<div class="no_preview"><p>Sorry, No preview</p></div>';
					}
					 echo '<form method="post" class="image-'.$id.' delete_image">'
					 .'<input class="image_name" type="hidden" value="'.$image_name.'" name="image_name" />'
					 .'<input class="image_id" type="hidden" value="'.$id.'" name="image_id" />'
					 .'<div class="picture_box"><input type="submit" value="Delete" class="delete_btn"/></div>'
					 .'</form></li>';
				 }else{
					//if the image doesnt exist in our folder, but does exist in the DB delete it from db.
					$id = $image['id'];
					$helpers->sqlDelete('images', "id = $id");	
				 }
			}
			
		}
		
		?>
	</ul>
	
	
	<?php $pager->ShowPaging(); ?>
</div>

<?php
	}else{
		header('Location: ?tpl=default_view#dashboard');
	}
?> 	
