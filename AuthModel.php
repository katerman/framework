<?php

class AuthModel{

	static $db;
	
	public function __construct($dsn, $user, $pass){
		try{
			$this->db = new PDO($dsn, $user, $pass);
				
		} catch (PDOException $e) {
			var_dump($e);		
		}
		//$this->db->setAttribute(\PDO::ATTR_ERRMODE, \PDO::ERRMODE_EXCEPTION);
	}
	
	//get users
	public function getUserByNamePass($name, $pass){
		$stmt = $this->db->prepare("
			SELECT user_Id AS id, user_uName AS name, user_Fullname AS fullname, user_Access AS access
			FROM users
			WHERE (user_uName = :name)
				AND (user_Pass = MD5(CONCAT(user_salt,:pass)))
		");
		if ($stmt->execute(array(':name' => $name, ':pass' => $pass))){
			$rows = $stmt->fetchAll(PDO::FETCH_ASSOC);
			if(count($rows) === 1) {
				return $rows[0];
			}
		}
		return array();//If the expected successful return is an array, the failed return should be an empty array
	}//end of get users.
	
	public function sql($select = "*", $table="*", $values="*", $times="1", $where="", $type = "echo"){
		//die(print_r(debug_backtrace(),true));
		
		$stmt = $this->db->prepare("SELECT $select FROM $table $where");
		try {
			if ($stmt->execute()) {
				$results = $stmt->fetchAll(PDO::FETCH_ASSOC);
			}
		}
		catch(PDOException $e){
			echo "Query Failed - users";
		}			
		
		$arr = array();
		if (is_array($results)){
			foreach($results as $rkey=>$r){

				foreach($values as $v){			
						
					if($type != "array"){

						if($rkey < $times || $values != false || $values != null){
							if($type == "return"){
								return $r[$v];
							}else{
								echo $r[$v];
							}						
						}
					}else{
						array_push($arr, $r[$v]);
					}
				}
			}		
		}
		
		if(sizeof($arr) > 0){
			return $arr;
		}
	}

	
	
	public function getQuery($query="page", $type="echo"){ /* Default is to ech out the query, but including a second argument called return you can return the query instead */
		$q = htmlentities($query);
		$r = $_GET[$q];
		
		if($type == "return"){
			return $r;		
		}else{
			echo $r;
		}
	}
	
}


?>