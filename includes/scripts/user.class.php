<?php

/**
 * user class - Information of the current logged in user
 */
class user {
	
    public function __construct(){
		$this->user = (isset($_SESSION['userInfo']) ? $_SESSION['userInfo'] : null );
    }		
    
	function get_Fullname(){
		return $this->user['fullname'];
	}
	
	function get_Name(){
		return $this->user['name'];
	}	
	
	function get_Id(){
		return $this->user['id'];
	}	
	
	function get_Access(){
		return $this->user['access'];
	}		
	
	function get_Permissions(){
		return $this->user['permissions'];
	}		

	function get_Comments(){
		return $this->user['comments'];
	}	

	function get_Scattershot(){
		return $this->user['scattershot'];
	}
	
	function debug(){
		echo '<div style="border: 1px solid red;"><p style="color:red;">user.class DEBUG:<p> ';	
		print_r($this->user);
		echo '</div>';	

	}
  
}

