<?

class helpers {
	
	public function url($t){ //Return url based on arguments (full, base, fullpage, folder), $type, $amount = for folder levels
		switch ($t) {
		
		    case full:
			    if(isset($_SERVER['HTTPS'])){
			        $protocol = ($_SERVER['HTTPS'] && $_SERVER['HTTPS'] != "off") ? "https" : "http";
			    }
			    else{
			        $protocol = 'http';
			    }
			    return $protocol . "://" . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
			break;
		        
		    case base:
		        return $_SERVER['HTTP_HOST'];
	        break;
		        
		    case fullpage:
				$url=end(explode('/',$_SERVER['PHP_SELF']));
				$url=str_replace($scriptname,'',$_SERVER['PHP_SELF']);				
				
				return $url;
			break;
			
			case folder:
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
 		}	    	    
	}

    public function debugAll(){
	    $x = print '<pre>' . print_r($GLOBALS) . '</pre>';
	    return $x;
   }
   
	public function debugOpts($array, $type){
		switch ($type) {
			case printr:
				$x = print '<pre>' . print_r($array) . '</pre>';
				return $x;
			break;
				
	
			case vardump:
				$x = print '<pre>' . var_dump($array) . '</pre>';
				return $x;
			break;
		}	

   }
	

}
	
?>