<h1> Lets add a user!</h1>

		<? 								
					    

			$addToken = $security->generateFormToken('add_token'); 
			
		?>
		<form id="add_form" class="form" action="" method="" accept-charset="utf-8">
				
			<label for="user_uname">Username</label><br/>
            <input id="user_uname" name="username" value="" placeholder="Username" class="required"><br/>
			
			<label for="user_pass">Password</label><br/>
            <input id="user_pass" name="password" value="" placeholder="Password" class="required"><br/>
		
			<label for="user_fullname">Full Name</label><br/>
            <input id="user_fullname" name="fullname" value="" placeholder="Full Name" class="required"><br/>
			
			<label for="radio_admin">Admin</label>
			<input id="radio_admin" type="radio" name="access" value="1">
			
			<label for="radio_user">User</label>
			<input id="radio_user" type="radio" name="access" value="2" checked><br/>
			
			<input type="hidden" id="token" name="token" value="<?php echo $addToken; ?>">
			<input type="hidden" id="update_type" name="update_type" value="user">
			
			<input type="submit" value="Submit" class="btn">
			<p class="feedback_text hidden"></p>
		</form>
		
		

		