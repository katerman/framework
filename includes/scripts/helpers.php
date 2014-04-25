<?php

class helpers {
	
    public function __construct($dsn, $db_user, $db_pass){
        $this->db = new PDO($dsn, $db_user, $db_pass);
    }		
	/**
	 * url function.
	 * 
	 * @access public
	 * @static
	 * @param mixed $t
	 * @return full, base, fullpage, folder, lastpath, current
	 */
	public static function url($t){ //Return url based on arguments (full, base, fullpage, folder), $type, $amount = for folder levels
		switch ($t) {
		
		    case 'full':
			    if(isset($_SERVER['HTTPS'])){
			        $protocol = ($_SERVER['HTTPS'] && $_SERVER['HTTPS'] != "off") ? "https" : "http";
			    }
			    else{
			        $protocol = 'http';
			    }
			    return $protocol . "://" . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
			break;
		        
		    case 'base':
		        return $_SERVER['HTTP_HOST'];
	        break;
		        
		    case 'fullpage':
				$url=end(explode('/',$_SERVER['PHP_SELF']));
				$url=str_replace($scriptname,'',$_SERVER['PHP_SELF']);				
				
				return $url;
			break;
			
			case 'folder':
				$request = parse_url($_SERVER['REQUEST_URI']);
				$path = $request["path"];
				
				$result = trim(str_replace(basename($_SERVER['SCRIPT_NAME']), '', $path), '/');
				
				$result = explode('/', $result);

				$max_level = 3;
				while ($max_level < count($result)) {
				    unset($result[0]);
				}
				$result = '/'.implode('/', $result);
				return $result;
			break;
			
			case 'lastpath':
				$url = basename($_SERVER['PHP_SELF']);
				
				return $url;
			break;
			
			case 'current':
			    if(isset($_SERVER['HTTPS'])){
			        $protocol = ($_SERVER['HTTPS'] && $_SERVER['HTTPS'] != "off") ? "https" : "http";
			    }
			    else{
			        $protocol = 'http';
			    }
			    
			    				$request = parse_url($_SERVER['REQUEST_URI']);
				$path = $request["path"];
				
				$result = trim(str_replace(basename($_SERVER['SCRIPT_NAME']), '', $path), '/');
				
				$result = explode('/', $result);

				$max_level = 3;
				while ($max_level < count($result)) {
				    unset($result[0]);
				}
				$result = '/'.implode('/', $result);
			    
			    
			    return $protocol . "://www." . $_SERVER['HTTP_HOST'] . $result . '/';
			break;
 		}	    	    
	}
	
	/**
	 * getQuery function.
	 * 
	 * @access public
	 * @param string $query (default: "page")
	 * @param string $type (default: "echo")
	 * @return query as param
	 */
	public function getQuery($query="page", $type="echo"){ /* Default is to echo out the query, but including a second argument called return you can return the query instead */
		if(isset($_GET[$query])){
			$r = htmlentities($_GET[$query]);

		}else{
			$r = '';
		}
		
		if($type == "return"){
			return $r;		
		}else{
			echo $r;
		}
		
	}	


	/**
	 * custom_clean function.
	 * 
	 * @access public
	 * @param mixed $document = text/code you're passing in to be sanitized 
	 * @param bool $js (default: true) = clean js true/false
	 * @param bool $html (default: true) = clean html true/false
	 * @param bool $styles (default: true) = clean styling true/false
	 * @param bool $cdata (default: true) = clean cdata true/false
	 * @param bool $php (default: true) = clean php tag true/false
	 * @return cleaned text/code
	 */
	function custom_clean($document, $js = true, $html = true, $styles = true, $cdata = true, $php = true){ 
		$search = array();
		
		if($js){array_push($search, '@<script[^>]*?>.*?</script>@si');}
		if($html){array_push($search, '@<[\/\!]*?[^<>]*?>@si');}
		if($styles){array_push($search, '@<style[^>]*?>.*?</style>@siU');}
		if($cdata){array_push($search, '@<![\s\S]*?--[ \t\n\r]*>@');}
		if($php){array_push($search, '(<\?{1}[pP\s]{1}.+)');}
		
		$text = preg_replace($search, '', $document); 
		return $text; 
		
	}
	

	/**
	* easy image resize function
	* @param  $file - file name to resize
	* @param  $width - new image width
	* @param  $height - new image height
	* @param  $proportional - keep image proportional, default is no
	* @param  $output - name of the new file (include path if needed)
	* @param  $delete_original - if true the original image will be deleted
	* @param  $use_linux_commands - if set to true will use "rm" to delete the image, if false will use PHP unlink
	* @param  $quality - enter 1-100 (100 is best quality) default is 100
	* @return boolean|resource
	*/
	function smart_resize_image($file,
								$width              = 0, 
								$height             = 0, 
								$proportional       = false, 
								$output             = 'file', 
								$delete_original    = true, 
								$use_linux_commands = false,
								$quality = 100
	) 
  	{
      
	if ( $height <= 0 && $width <= 0 ) return false;
	
	# Setting defaults and meta
	$info                         = getimagesize($file);
	$image                        = '';
	$final_width                  = 0;
	$final_height                 = 0;
	list($width_old, $height_old) = $info;
	$cropHeight = $cropWidth = 0;
	
	# Calculating proportionality
	if ($proportional) {
		if      ($width  == 0)  $factor = $height/$height_old;
		elseif  ($height == 0)  $factor = $width/$width_old;
		else                    $factor = min( $width / $width_old, $height / $height_old );

		$final_width  = round( $width_old * $factor );
		$final_height = round( $height_old * $factor );
    }
	else {
		$final_width = ( $width <= 0 ) ? $width_old : $width;
		$final_height = ( $height <= 0 ) ? $height_old : $height;
		$widthX = $width_old / $width;
		$heightX = $height_old / $height;
		
		$x = min($widthX, $heightX);
		$cropWidth = ($width_old - $width * $x) / 2;
		$cropHeight = ($height_old - $height * $x) / 2;
	}

    # Loading image to memory according to type
	switch ( $info[2] ) {
		case IMAGETYPE_JPEG:  $image = imagecreatefromjpeg($file);  break;
		case IMAGETYPE_GIF:   $image = imagecreatefromgif($file);   break;
		case IMAGETYPE_PNG:   $image = imagecreatefrompng($file);   break;
		default: return false;
	}
    
    
    # This is the resizing/resampling/transparency-preserving magic
	$image_resized = imagecreatetruecolor( $final_width, $final_height );
	if ( ($info[2] == IMAGETYPE_GIF) || ($info[2] == IMAGETYPE_PNG) ) {
		$transparency = imagecolortransparent($image);
		$palletsize = imagecolorstotal($image);

		if ($transparency >= 0 && $transparency < $palletsize) {
			$transparent_color  = imagecolorsforindex($image, $transparency);
			$transparency       = imagecolorallocate($image_resized, $transparent_color['red'], $transparent_color['green'], $transparent_color['blue']);
			imagefill($image_resized, 0, 0, $transparency);
			imagecolortransparent($image_resized, $transparency);
		}
		
		elseif ($info[2] == IMAGETYPE_PNG) {
			imagealphablending($image_resized, false);
			$color = imagecolorallocatealpha($image_resized, 0, 0, 0, 127);
			imagefill($image_resized, 0, 0, $color);
			imagesavealpha($image_resized, true);
		}
    }
    imagecopyresampled($image_resized, $image, 0, 0, $cropWidth, $cropHeight, $final_width, $final_height, $width_old - 2 * $cropWidth, $height_old - 2 * $cropHeight);
	
	
    # Taking care of original, if needed
    if ( $delete_original ) {
      if ( $use_linux_commands ) exec('rm '.$file);
      else @unlink($file);
    }

    # Preparing a method of providing result
	switch ( strtolower($output) ) {
		case 'browser':
			$mime = image_type_to_mime_type($info[2]);
			header("Content-type: $mime");
			$output = NULL;
			break;
		case 'file':
			$output = $file;
			break;
		case 'return':
			return $image_resized;
			break;
		default:
			break;
    }
    
    # Writing image according to type to the output destination and image quality
	switch ( $info[2] ) {
		case IMAGETYPE_GIF:   imagegif($image_resized, $output);    break;
		case IMAGETYPE_JPEG:  imagejpeg($image_resized, $output, $quality);   break;
		case IMAGETYPE_PNG:
			$quality = 9 - (int)((0.9*$quality)/10.0);
			imagepng($image_resized, $output, $quality);
			break;
		default: return false;
	}

	return true;
	}
	

	/**
	 * sqlSelect function.
	 * 
	 * @access public
	 * @static
	 * @param string $select (default: "*") column(s) name
	 * @param string $table (default: "*") table name
	 * @param string $table (default: "") more on this later
	 * @param string $where (default: "") room for more after the select.
	 * @return - an array of data from the DB
	 */
	 public function sqlSelect($select = "*", $table="*", $values="", $where=""){
		//die(print_r(debug_backtrace(),true));
		$stmt = $this->db->prepare("SELECT $select FROM $table $where");
		try {
			if ($stmt->execute()) {
				$results = $stmt->fetchAll(PDO::FETCH_ASSOC);
			}
		}
		catch(PDOException $e){
			echo "Query Failed -> sqlselect() ". $e;
		}			
		
		$arr = array();
		if (is_array($results)){
			foreach($results as $rkey=>$r){
				
				if($values != ""){
					foreach($values as $v){			
						array_push($arr,$r[$v]);
					}
				}else{
					array_push($arr,$r);
				}
				
			}
			return $arr;		
		}
	}
	
	/**
	 * sqlDelete function.
	 * 
	 * @access public
	 * @param string $select (default: "")
	 * @param string $table (default: "")
	 * @param string $where (default: "")
	 * @return - delete something from the DB
	 */
	public function sqlDelete($select = "", $table="", $where=""){

		//die(print_r(debug_backtrace(),true));
		$stmt = $this->db->prepare("DELETE $select FROM $table $where");
		try {
			if ($stmt->execute()) {
				$results = $stmt->fetchAll(PDO::FETCH_ASSOC);
			}
		}
		catch(PDOException $e){
			echo "Query Failed -> sqlDelete() ". $e;
		}			

	}	
	
}
