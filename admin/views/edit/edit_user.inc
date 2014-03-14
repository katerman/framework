
	
		<?php
				$uid = $helpers->getQuery('userid','return');
				$z = $model->sqlSelect("*" , "users", "", "WHERE users_Id = $uid" );
				
				
				if(strlen($z['0']['user_FullName']) > 0){	
					echo '<h1>Edit '. $z['0']['user_FullName'].'</h1>';	
				}else{
					echo '<h1>Edit User</h1>';	
				}
				
				echo '<table>
						<tr class="th">
							<td>user id</td>
							<td>Username</td>
							<td class="hidden">password</td>
							<td>full name</td>
							<td>salt</td>
							<td class="hidden">comments</td>
							<td>access</td>
						</tr>
					';		
								  
				foreach($z as $value) {
					echo '<tr>'.
							'<td>'.$value['users_Id'].'</td>'
							.'<td>'.$value['user_uName'].'</td>'
							.'<td class="hidden">'.$value['user_Pass'].'</td>'
							.'<td>'.$value['user_FullName'].'</td>'
							.'<td>'.$value['user_Salt'].'</td>'
							.'<td class="hidden">'.$value['user_Comments'].'</td>'
							.'<td>'.$value['user_Access'].'</td>'
						 .'</tr>';
				}				
				echo '</table>';		
					    

			$token = $security->generateFormToken('token'); 
			
			$user_id = $helpers->stripcleantohtml($z[0]['users_Id']);
			$user_name = $helpers->stripcleantohtml($z[0]['user_uName']);
/* 			$user_password = $helpers->stripcleantohtml($z[0]['user_Pass']); */
			$user_fullname = $helpers->stripcleantohtml($z[0]['user_FullName']);
			$user_salt = $helpers->stripcleantohtml($z[0]['user_Salt']);
			$user_access = $helpers->stripcleantohtml($z[0]['user_Access']);
			$user_comments = htmlentities($z[0]['user_Comments']); 
			$user_custom_perms = unserialize($z[0]['user_custom_perms']);
			
			//print_r($user_custom_perms);
		?>
        
		<form id="edit_form" class="form" action="" method="" accept-charset="utf-8">
			
			<input type="hidden" id="user_id" name="user_id" value="<?php echo $user_id; ?>"><br/>

				
			<label for="user_uname">Username</label><br/>
            <input id="user_uname" name="username" value="<?php echo $user_name; ?>" placeholder="Username" class="required"><br/>
			
			<label for="user_pass">Password</label><br/>
            <input id="user_pass" name="password" value="" placeholder="Enter a password to update the current password."><br/>
		
			<label for="user_fullname">Full Name</label><br/>
            <input id="user_fullname" name="fullname" value="<?php echo $user_fullname; ?>" placeholder="Full Name" class="required"><br/>
			
			<label for="user_comments">Comments </label><br/>
            <textarea id="user_comments" class="html-code" name="user_comments" placeholder="User Comments" class=""><?php echo $user_comments; ?></textarea><br/>
			
			<?php 
				include_once 'edit_user_perms.inc';
			?>
												
			<input type="hidden" id="token" name="token" value="<?php echo $token; ?>">
			<input type="hidden" id="update_type" name="update_type" value="user">
			
			<br><br/>
			
			<input type="submit" value="Submit" class="btn">
			<p class="feedback_text hidden"></p>
		

		
		</form>
		
		

		