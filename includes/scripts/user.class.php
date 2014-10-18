<?php

/**
 * user class Current information about the logged in user, and functions related to users
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
		return unserialize($this->user['permissions']);
	}

	function get_Comments(){
		return $this->user['comments'];
	}

	/**
	 * is_New function. This function checks if the passed in username is already in the DB or not
	 *
	 * @access public
	 * @param mixed $username Supply a username to determine is new or not
	 * @return void True or false depending on if the user is already in the db
	 */
	function is_New($username){
		global $helpers;
;
		$sql = $helpers->sqlSelect("user_uName" , "users", "", "WHERE user_uName LIKE '$username'");
		if(count($sql) > 0){
			return false;
		}

		return true;
	}

	/**
	 * get_userById function. Used to return an array of a user information where information is specific to the users id
	 *
	 * @access public
	 * @param int $id Should be an int of the user (users_id)
	 * @return void Returns array of user information
	 */
	function get_userById($id){
		global $helpers;
		$sql = $helpers->sqlSelect("*", "users", false, "WHERE users_id = '$id'");
		return $sql;
	}

	function get_maxPermissions(){
		$max_perms = 'a:4:{s:6:"config";s:1:"1";s:5:"pages";s:1:"1";s:5:"users";s:1:"1";s:6:"assets";a:6:{s:9:"top_level";s:1:"1";s:6:"upload";s:1:"1";s:8:"uploaded";s:1:"1";s:9:"templates";s:1:"1";s:6:"labels";s:1:"1";s:11:"scattershot";s:1:"1";}}';
		return $max_perms;
	}

	function get_minPermissions(){
		$min_perms = 'a:4:{s:6:"config";s:1:"0";s:5:"pages";s:1:"0";s:5:"users";s:1:"0";s:6:"assets";a:6:{s:9:"top_level";s:1:"0";s:6:"upload";s:1:"0";s:8:"uploaded";s:1:"0";s:9:"templates";s:1:"0";s:6:"labels";s:1:"0";s:11:"scattershot";s:1:"0";}}';
		return $min_perms;
	}

	function debug(){
		echo '<div style="border: 1px solid red;"><p style="color:red;">user.class DEBUG:<p> ';
		print_r($this->user);
		echo '</div>';

	}

}

