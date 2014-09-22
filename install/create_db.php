<?php

	$data = array();		
	
	if(!is_file('../refined_framework.sql')){
		die('refined_framework.sql was not found.');
	}
	
	if(is_file('../includes/scripts/app.php')){
		include_once('../includes/scripts/app.php');
		global $_CONFIG;
	}
	
	function Delete($path) {
	    if (is_dir($path) === true)
	    {
	        $files = array_diff(scandir($path), array('.', '..'));
	
	        foreach ($files as $file)
	        {
	            Delete(realpath($path) . '/' . $file);
	        }
	
	        return rmdir($path);
	    }
	
	    else if (is_file($path) === true)
	    {
	        return unlink($path);
	    }
	
	    return false;
	}	
	
	if($_POST && is_object($_CONFIG)){		
			
		$data['status'] = 'working';	
	
		$errors = array(
			"name" => "Name is required",
			"db_ip" => "Host/IP is required", 
			"db_name" => "Database Name is required",
			"db_port" => "Database Port is required", 
			"db_username" => "Database Username is required",
			"db_pw" => "Database Password is required",
			'username' => 'Username is required',
			'password' => 'Password is required',
			'full_name' => 'Full Name is required'
		);
	
		$failure = true;
		
		foreach($_POST as $key=>$post){
			$data['values'][$key] = $post;

			if(strlen((string)$post) > 0){
				if($failure === true){
					$failure = false;
				}
			}else{
				$data['fields'][$key] = $errors[$key];				
			}			
		}

		if($failure === false){
			
			//post vars pulled from data
			$name = $data['values']['name'];
			$db_ip = $data['values']['db_ip'];
			$db_name = $data['values']['db_name'];
			$db_port = $data['values']['db_port'];
			$db_user = $data['values']['db_username'];
			$db_pw = $data['values']['db_pw'];
			
			$username = $data['values']['username'];
			$password = $data['values']['password'];
			$fullname = $data['values']['full_name'];
			
			function random_numbers($digits){
				$min = pow(10, $digits - 1);
				$max = pow(10, $digits) - 1;
				return mt_rand($min, $max);
			}
			
			$salt = random_numbers(8);
			
			$dsn = "mysql:host=$db_ip;port=$db_port;dbname=$db_name";
		
			try{
				$db = new PDO($dsn, $db_user, $db_pw);
			}catch(PDOException $e){
				$data['status'] = 'failed';
				error_log($e->getMessage());
			}		
			
			if($data['status'] != 'failed'){
			
				$handle = fopen($_CONFIG->config_path.'app/db.php','w');
				
				//credentials
				fwrite($handle, '<?php 
									$dsn = "mysql:host='.$db_ip.';port='.$db_port.';dbname='.$db_name.'";');
				fwrite($handle, '	$db_user= "'.$db_user.'";');
				fwrite($handle, '	$db_pass = "'.$db_pw.'";');
				
				//try
				fwrite($handle, '
							try {
								 $db = new PDO($dsn, $db_user, $db_pass);
							}
								 catch(PDOException $e) {
								 die("Failed to connect to the database: " . $e->getMessage());
						    }');
				
				fclose($handle);
				
				//user
				$max_perms = 'a:4:{s:6:"config";s:1:"1";s:5:"pages";s:1:"1";s:5:"users";s:1:"1";s:6:"assets";a:6:{s:9:"top_level";s:1:"1";s:6:"upload";s:1:"1";s:8:"uploaded";s:1:"1";s:9:"templates";s:1:"1";s:6:"labels";s:1:"1";s:11:"scattershot";s:1:"1";}}';			
				$values = array(
					'user_uName' => $username,
					'user_FullName' => $fullname,
					'user_Access' => 1,
					'user_custom_perms' => $max_perms,
					'user_Salt' => $salt,
					'user_Pass' => md5($salt.$password)
				);
			
				include_once($_CONFIG->config_path.'app/db.php');
				$helpers = new helpers($dsn, $db_user, $db_pw);
				
				$helpers->sqlAdd('users', $values);

				$sql = file_get_contents('../refined_framework.sql');
				
				$helpers->sqlRaw($sql);
				
				$helpers->sqlUpdate('config', array('site_name' => $name), '`id`=1');
				
				$data['status'] = 'Installing Finished, installing folder will now delete itself.';

				$data['installed'] = true;

				Delete($_CONFIG->config_path.'install');
				
				echo json_encode($data);
				
			}else{
				$data['status'] = 'Installing Failed DB connection faulty.';		
				echo json_encode($data);
			}
		}else{
			$data['status'] = 'Installing Failed, missing fields.';		
			echo json_encode($data);
		}
		
	}else{
		echo json_encode(array('status' => 'config not set, or you\'re doing it wrong'));
	}
	
