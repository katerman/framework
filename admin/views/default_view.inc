		
		<p>Welcome back, <?php echo htmlentities($data['fullname']);?>.</p>
		
		<div class="dashboard">
		<?php
			global $model;
			
			$user_id = $_SESSION['userInfo']['id'];
			$user = $model->sqlSelect("*" , "users", "", "WHERE users_Id = $user_id");
			
			echo $user['0']['user_Comments'];
		?>
		</div>