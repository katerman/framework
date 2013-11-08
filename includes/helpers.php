<?

class helpers {
	
	static $db;
	static $model;
	
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
			
			case lastpath:
				$url = basename($_SERVER['PHP_SELF']);
				
				return $url;
			break;
			
			case current:
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
	
	
	public function getQuery($query="page", $type="echo"){ /* Default is to echo out the query, but including a second argument called return you can return the query instead */
		$q = htmlentities($query);
		$r = $_GET[$q];
		
		if($type == "return"){
			return $r;		
		}else{
			echo $r;
		}
	}
	
	function cleantohtml($s){
		//should contain html
		return strip_tags(htmlentities(trim(stripslashes($s))), ENT_NOQUOTES, "UTF-8");
	}	

	function stripcleantohtml($s){
		// Use: Anything that shouldn't contain html (pretty much everything that is not a textarea)
		return htmlentities(trim(strip_tags(stripslashes($s))), ENT_NOQUOTES, "UTF-8");
	}	

}
	
?>