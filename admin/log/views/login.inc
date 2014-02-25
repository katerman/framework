<div id="content" class="container">

	<div class="sixteen columns">
		<form id="login_form" action="?" method="POST">
			<h1>Admin Log</h1>
			
			<p>Please, Log in.</p>
			
				
				<div class="input-row">
					<label for="username"><div class="icon-user"></div></label>
					<input type="text" name="username" id="username" maxlength="20" size="20"  placeholder="username" class="required"/>
				</div>					
				
				<div class="input-row">
					<label for="password"><div class="icon-pass"></div></label>
					<input type="password" name="password" id="password" placeholder="password" maxlength="20" size="20" class="required"/>
				</div>

					

				
			<p class="feedback_text"></p>
			<input class="btn orange" type="submit"/>
			
		</form>
	</div>
</div>
<?
/*
	global $model;

	$x = $model->sqlSelect("*" , "users", "", "");
	print_r($x);
	
	$pw = MD5('12225687'.'halo12');
	echo $pw;
*/
?>