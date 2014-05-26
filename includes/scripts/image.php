<?php

	include_once 'app.php';	
	
	$helpers = new helpers($dsn, $db_user, $db_pass);

	function is_image($path){
	    $a = getimagesize($path);
	    $image_type = $a[2]; //$a[0] and $a[1] are the width and height of the image. $a[2] has the image type.
	     
	    if(in_array($image_type , array(IMAGETYPE_GIF , IMAGETYPE_JPEG ,IMAGETYPE_PNG , IMAGETYPE_BMP))){
	        return true;
	    }
	    return false;
	}
	
	//<img src="includes/scripts/image.php?w=1000&fit=false&h=120&file=refined.png">
	//website.com/includes/scripts/image_resize.php?w=20&h=10&file=image.png
	if($_GET['w'] && $_GET['h'] && $_GET['file']){
		
		$width = $_GET['w'];
		$height = $_GET['h'];
		$file = $_GET['file'];
		
		$uploads_path = '../../uploads/';
		$temp_path = '../../uploads/temp/';

		//proportinal = fit
		if(isset($_GET['file']) && file_exists($uploads_path.$_GET['file'])){
			$file = $_GET['file'];
		}else{
			die('File does not exists');
 		}
				
		//proportinal = fit
		if(isset($_GET['fit']) && $_GET['fit'] == 1){
			$fit = (bool)true;
		}else{
			$fit = (bool)false;
		}
		
		//quality
		if(isset($_GET['q'])){
			$quality = $_GET['q'];
		}else{
			$quality = 60;
		}
		
		if($width && $height){
			$filename = $file.'-w'.$width.'h'.$height;
		}else{
			die('no width and height');
		}
		
		function display_correct_headers($img){
			switch($img){
				case 1: 
					header('Content-Type: image/gif');
					return true;
					break;
				case 2:
					header('Content-Type: image/jpg');
					return true;
					break;
				case 3:
					header('Content-Type: image/png');
					return true;
					break;
				case 6:
					header('Content-Type: image/bmp');
					return true;
					break;
				default: 
					header('Content-Type: image/jpg');
					return true;
				
			}
		}		
		
		if(file_exists($uploads_path.$file) && is_image($uploads_path.$file) && !file_exists($temp_path.$filename)){
			$helpers->smart_resize_image($uploads_path.$file, $width, $height, $fit, $temp_path.$filename, false, false, $quality);			
			display_correct_headers(exif_imagetype ($temp_path.$filename));		
			echo file_get_contents($temp_path.$filename);

		}elseif(file_exists($temp_path.$filename) && is_image($temp_path.$filename)){
			display_correct_headers(exif_imagetype ($temp_path.$filename));		
			echo file_get_contents($temp_path.$filename);


		}else{
			die('The file might not exist or is not an image.');
		}
		
				
	}else{
		die('You need to supply a width and height, and a file name');
	}
		
	
?>