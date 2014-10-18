<?php

$runnable = false;

if($runnable === true){
	
	include_once 'app.php';
	$helpers = new helpers();
	
	function is_image($path){
		$a = getimagesize($path);
		$image_type = $a[2]; //$a[0] and $a[1] are the width and height of the image. $a[2] has the image type.
	
		if(in_array($image_type , array(IMAGETYPE_GIF , IMAGETYPE_JPEG ,IMAGETYPE_PNG , IMAGETYPE_BMP))){
			return true;
		}
		return false;
	}
	
	$dirname = "../../uploads/";
	$images = glob("{$dirname}*.*");
	if($images){
		foreach($images as $k=>$image){
			$image_path = $images;
			$image = str_replace('../../uploads/', '', $image);
			$today = date("Y-m-d H:i:s");
			$added = 0;
			//echo '<img src="'.$image_path.'">'. $image . '<br>';
	
			$select = $helpers->sqlSelect("image_name", "images", false, "WHERE image_name LIKE '%$image%'");
			
			//print_r(count($select));
			if(count($select) == 0){
				$values = array(
					'image_name' => $image,
					'image_created' => $today
				);
				$helpers->sqlAdd('images', $values, false);
				echo "Image: $image added to DB. <br>";
			}else{
				echo "it appears a similar image is already in the db named: $image <br>";
			}
			
		}
		
		echo "<h2>$added of ". count($images)  ." added.</h2>";
	
	}

}else{
	die('This needs to be runnable.');
}
