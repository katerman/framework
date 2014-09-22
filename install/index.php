<?php

	$no_db = false;

	if(is_file('../includes/scripts/app.php')){
		include_once('../includes/scripts/app.php');
	}
	
	try{
		global $dsn, $db_user, $db_pass;
		$db = new PDO($dsn, $db_user, $db_pass);
	}
	catch(PDOException $e){
	   $no_db = true;
	}
	
	if($no_db){

?>

<html>
	<head>
		<title>Refined Install</title>
		<link rel="stylesheet" href="global.css" type="text/css" media="screen">
	</head>
	<body>
	
		<div id="container">
			<h1>Welcome to RefinedCMS</h1>
			<p> This form will help you install RefinedCMS. All you have to do is fill in the fields below. Make sure you have a Database already created with the name you supply.</p>
		
		
			<form id="form" method="" action=""> 
				<h2>Site Info</h2>
				<label for="name">Site/Company Name<span class="error">*</span></label>
				<input id="name" name="name" type="text" class="required" value="" placeholder="Site/Company Name">


				<h2>Database Info</h2>
				<p>Database info will be stored in <em>/app/db.php</em></p>
				
				<label for="db_ip">Database IP/Host<span class="error">*</span></label>
				<input id="db_ip" name="db_ip" type="text" class="required" value="" placeholder="Database IP"/>

				<label for="db_name">Database Name<span class="error">*</span></label>
				<input id="db_name" name="db_name" type="text" class="required" value="" placeholder="Database Name"/>

				<label for="db_port">Database Port<span class="error">*</span></label>
				<input id="db_port" name="db_port" type="text" class="required" value="3306" placeholder="Database IP"/>

				<label for="db_username">Database Username<span class="error">*</span></label>
				<input id="db_username" name="db_username" type="text" class="required" value="" placeholder="Database Username"/>

				<label for="db_pw">Database Password<span class="error">*</span></label>
				<input id="db_pw" name="db_pw" type="text" class="required" value="" placeholder="Database Password"/>

				<h2>Admin User</h2>
				<label for="full_name">Full Name<span class="error">*</span></label>
				<input id="full_name" name="full_name" type="text" class="required" value="" placeholder="Admin Full Name">
				
				<label for="username">Username<span class="error">*</span></label>
				<input id="username" name="username" type="text" class="required" value="" placeholder="Admin Username">

				<label for="password">Password<span class="error">*</span></label>
				<input id="password" name="password" type="text" class="required" value="" minlength="6" placeholder="Admin Password">


				<p class="message"></p>

				<input type="submit" class="btn orange" id="submit" value="Install"/>
			</form>
		</div>
			
		<script type="text/javascript" src="//code.jquery.com/jquery-1.11.1.min.js"></script>
		<script type="text/javascript" src="../includes/js/jquery.validate.min.js"></script>
		<script type="text/javascript" src="../includes/js/jquery.form.js"></script> 		
		<script>
			$(document).ready(function(){

				var install_btn = $('#submit');
								
				install_btn.on('click', function(e){

					$('#form').validate({
						submitHandler: function(form) {
							$('#form').ajaxSubmit({
								url: "create_db.php",
								type: "POST",
								data: $(this).serialize(),
								timeout: 60000,
								clearForm: false,
								cache: false,
								dataType: 'json',
								success: function(data) {
									
									if(data['fields'] != undefined){
										var fields = data['fields'];
										$.each( fields, function( i, val ) {
											console.log(i + '  ' + val);
											$(i+'_err').remove();
											$('#'+i).after('<label class="error '+i+'_err" for="'+i+'">'+ val +'</label>');
										});
									}
									
									if(data['status'] != undefined){
										var status_msg = data['status'];
										$('.message').text(status_msg);
									}	
									
									if(data['installed'] == true){

										install_btn.after('<a style="margin-left:10px;" href="<?php echo $_CONFIG->root_path.'admin' ?>" class="btn">Admin</a>');
										install_btn.after('<a href="<?php echo $_CONFIG->root_path ?>" class="btn">Application</a>');
										install_btn.remove();
									}
								},
								error: function(x, status, error) {
									console.log('Error======');
									console.log('jqXHR' + JSON.stringify(x));
									console.log('text status' + status);
									console.log('error thrown' + error);
								}
							});
						}
					});
					
					
					
				});
				
			});
		</script>
			
	</body>
</html>

<?php
}else{
	die('Delete install folder');
}
?>

