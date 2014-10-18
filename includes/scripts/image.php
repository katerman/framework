<?php

	include_once 'app.php';

	global $_CONFIG;

	$helpers = new helpers();

	function is_image($path){
	    $a = getimagesize($path);
	    $image_type = $a[2]; //$a[0] and $a[1] are the width and height of the image. $a[2] has the image type.

	    if(in_array($image_type , array(IMAGETYPE_GIF , IMAGETYPE_JPEG ,IMAGETYPE_PNG , IMAGETYPE_BMP))){
	        return true;
	    }
	    return false;
	}

	//<img src="includes/scripts/image.php?w=1000&fit=false&h=120&file=refined.png">
	//website.com/includes/scripts/image.php?w=20&h=10&file=image.png
	if( (isset($_GET['w']) || isset($_GET['h'])) && $_GET['file']){

		$width = isset($_GET['w']) ?  (int)$helpers->custom_clean($_GET['w']) : null;
		$height = isset($_GET['h']) ?  (int)$helpers->custom_clean($_GET['h']) : null;
		$file = (string)$helpers->custom_clean($_GET['file']);

		$uploads_path = $_CONFIG->upload_path;
		$temp_path = $uploads_path.'temp/';

		if ( !is_dir( $temp_path ) ){
			if(!mkdir( $temp_path, 0755, true )){
				echo 'Could not create temp path for file creation.';
			}
		}

		//proportinal = fit
		if(isset($_GET['file']) && file_exists($uploads_path.$_GET['file'])){
			$file = $_GET['file'];
		}else{
			die('File does not exists');
 		}

		//proportinal = fit
		if(isset($_GET['fit']) && $_GET['fit'] == 1){
			$fit = 1;
		}else{
			$fit = 0;
		}

		//quality
		if(isset($_GET['q'])){
			$quality = $_GET['q'];
		}else{
			$quality = 90;
		}

		//decide the file name by what h/w we have
		if($height){
			$filename = $file.'-h'.$width;
		}

		if($width){
			$filename = $file.'-h'.$width;
		}

		if($width && $height){
			$filename = $file.'-w'.$width.'h'.$height;
		}else{
			$fit = 1;
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
		die('You need to supply a width or a height, and a file name');
	}


?>