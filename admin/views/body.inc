<?php
	global $model; 
/*
	echo 'full: ' . helpers::url(full) . '<br>';
	echo 'fullpage: ' . helpers::url(fullpage) . '<br>';
	echo 'folder: ' . helpers::url(folder) . '<br>';
	echo 'base: ' . helpers::url(base) . '<br>';
	echo 'lastpath: ' . helpers::url(lastpath);
*/



?>

<div id="header">
	<? echo '<h1>'.helpers::url(base).'</h1>'; ?>
	<p class="pull-right"><a class="logout" href="logout.php">Log out</a></p>

</div>


<div id="content"><!-- start content -->

	<div id="nav">

		<ul>
			<li>Content</li>
			<li>
				<ul class="dropdownBtn">
					<a href="#test1"><li>test</li></a>
					<li>test</li>
					<li>test</li>
				</ul>
			</li>
		</ul>		
		
		<ul>
			<li>Content</li>
			<li>
				<ul class="dropdownBtn">
					<li>test</li>
					<li>test</li>
					<li>test</li>
				</ul>
			</li>
		</ul>	
			
		<ul>
			<li>Content</li>
			<li>
				<ul class="dropdownBtn">
					<li>test</li>
					<li>test</li>
					<li>test</li>
				</ul>
			</li>
		</ul>		
		
	</div>

	<div id="display">
		<p>Welcome back, <?php echo htmlentities($data['fullname']);?>.</p>
		<p><? 
					
					 $model->sqlPages(    "*" /*select*/, 
										  "pages" /*from*/, 
										  array("page_template")/*column names*/, 
										  2 /*cycle# times*/,
										  'WHERE page_id = 0' /*where*/
									  ); 
											  
											   
		?></p>
	</div>
</div><!-- end content-->

<script src="//ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js"></script>
<script src="js/site.js" charset="utf-8"></script>