<h1> this is the <? $helpers->getQuery('pagename','echo'); ?> page</h1>

		<? 
				$uid = $helpers->getQuery('userid','return');
				$z = $model->sqlSelect("*" , "users", "", "WHERE users_Id = $uid" );
						
				echo '<table>
						<tr class="th">
							<td>user id</td>
							<td>Username</td>
							<td>password</td>
							<td>full name</td>
							<td>salt</td>
							<td>access</td>
						</tr>
					';		
								  
				foreach($z as $value) {
					echo '<tr>'.
							'<td>'.$value[users_Id].'</td>'
							.'<td>'.$value[user_uName].'</td>'
							.'<td>'.$value[user_Pass].'</td>'
							.'<td>'.$value[user_FullName].'</td>'
							.'<td>'.$value[user_Salt].'</td>'
							.'<td>'.$value[user_Access].'</td>'
						 .'</tr>';
				}				
				echo '</table>';		
					    

			$editToken = $security->generateFormToken('edit_token'); 
			
			$user_id = $helpers->stripcleantohtml($z[0][users_Id]);
			$user_name = $helpers->stripcleantohtml($z[0][user_uName]);
/* 			$user_password = $helpers->stripcleantohtml($z[0][user_Pass]); */
			$user_fullname = $helpers->stripcleantohtml($z[0][user_FullName]);
			$user_salt = $helpers->stripcleantohtml($z[0][user_Salt]);
			$user_access = $helpers->stripcleantohtml($z[0][user_Access]);

		?>
		
        
		<form id="edit_form" class="form" action="" method="" accept-charset="utf-8">
			
			<input type="hidden" id="user_id" name="user_id" value="<? echo $user_id; ?>"><br/>

				
			<label for="user_uname">Username</label><br/>
            <input id="user_uname" name="username" value="<? echo $user_name; ?>" placeholder="Username" class="required"><br/>
			
			<label for="user_pass">Password</label><br/>
            <input id="user_pass" name="password" value="" placeholder="Enter a password to update the current password."><br/>
		
			<label for="user_fullname">Full Name</label><br/>
            <input id="user_fullname" name="fullname" value="<? echo $user_fullname; ?>" placeholder="Full Name" class="required"><br/>
			
			<label for="radio_admin">Admin</label>
			<input id="radio_admin" type="radio" name="access" value="1"  <? if($user_access == '1'){ echo 'checked'; } ?>>
			
			<label for="radio_user">User</label>
			<input id="radio_user" type="radio" name="access" value="2" <? if($user_access == '2'){ echo 'checked'; } ?>><br/>
			
			<input type="hidden" id="token" name="token" value="<?php echo $editToken; ?>">
			<input type="hidden" id="update_type" name="update_type" value="user">
			
			<input type="submit" value="Submit" class="btn">
			<p class="feedback_text hidden"></p>
		

		
		</form>
		
		

		


		

		