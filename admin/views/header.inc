<?php
	global $helpers, $security;

	$user = new user();

	$name = $user->get_name();

?>

	<a href="?tpl=default_view" id="logo"><img src="<?php echo $_CONFIG->img_path; ?>admin/refined.png" alt="refined logo"></a>
	<ul id="header_ul">
		<li>
			<div class="fa fa-cog">
				<ul>
					<li><a href="index.php?userid=<?php echo $user->get_Id();?>&tpl=edit&type=edit_user"><span class="fa fa-user"></span><?php echo $name; ?></a></li>
					<li><a class="logout" href="logout.php"><span class="fa fa-leaf"></span>Log out</a></li>
				</ul>
			</div>
		</li>
	</ul>

