<?php
static $db;

class appModel{

	
	public function __construct($dsn, $user, $pass){
		try{
			$this->db = new PDO($dsn, $user, $pass);		
		}catch (PDOException $e){
			var_dump($e);		
		}
		$this->db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION); //throw errors
	}
	
	//get users
	public function getUserByNamePass($name, $pass){
		$stmt = $this->db->prepare("
			SELECT users_Id AS id, user_uName AS name, user_Fullname AS fullname, user_Access AS access
			FROM users
			WHERE (user_uName = :name)
				AND (user_Pass = MD5(CONCAT(user_salt,:pass)))
		");
		if ($stmt->execute(array(':name' => $name, ':pass' => $pass))){
			$rows = $stmt->fetchAll(PDO::FETCH_ASSOC);
			if(count($rows) === 1) {
				return $rows[0];
			}else{
				$e = header("HTTP/1.1 403 Forbidden");
			}
		}
		return array();//If the expected successful return is an array, the failed return should be an empty array
	}//end of get users.

}


?>