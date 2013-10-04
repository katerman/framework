<?php
	global $model; 
	global $helpers;
/*
	echo 'full: ' . helpers::url(full) . '<br>';
	echo 'fullpage: ' . helpers::url(fullpage) . '<br>';
	echo 'folder: ' . helpers::url(folder) . '<br>';
	echo 'base: ' . helpers::url(base) . '<br>';
	echo 'lastpath: ' . helpers::url(lastpath);
	
	$model->sql( "*" //select, 
					  "pages", //from
					  array("page_template"), //column names
					  2,  //cycle# time
					  "WHERE page_name = ".$model->getQuery('page', 'return')."", //where
					  "return" // type of return, echo, or return
				  ); 	
*/

?>

<div id="header">
	<? echo '<h1>'. $helpers->url(base).'</h1>'; ?>
	<p class="pull-right"><a class="logout" href="logout.php">Log out</a></p>

</div>


<div id="content"><!-- start content -->

	<div id="nav">

		<ul>
			<li>Content</li>
			<li>
				<ul class="dropdownBtn">
					<? 
					
						$x = $model->sql("*" /*select x*/,"pages" /*from*/,array("page_name") /*column names(array)*/,"144" /*iteration*/,"" /*where*/,"array" /*return or echo*/);
					
									
						foreach ($x as $key=>$value) {
							echo '<li><a href="?page='. $value .'">'. $value .'</a></li>';
						}
						
												
					?>
				</ul>
			</li>
		</ul>		
		
		<ul>
			<li>Content</li>
			<li>
				<ul class="dropdownBtn">
					<li><a href="#test1">test</a></li>
					<li><a href="#test1">test</a></li>
					<li><a href="#test1">test</a></li>
				</ul>
			</li>
		</ul>	
			
		<ul>
			<li>Content</li>
			<li>
				<ul class="dropdownBtn">
					<li><a href="#test1">test</a></li>
					<li><a href="#test1">test</a></li>
					<li><a href="#test1">test</a></li>
				</ul>
			</li>
		</ul>		
		
	</div>

	<div id="display">
		<p>Welcome back, <?php echo htmlentities($data['fullname']);?>.</p>
		<p><? 
					
				$model->sql( "*", //select
					  "pages", //from
					  array(""), //column names
					  100,  //cycle# time
					  "", //where
					  "echo"
				  ); 
											  
					echo $model->getQuery('page');
					   
		?></p>
	</div>
</div><!-- end content-->

<script src="//ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js"></script>
<script src="js/site.js" charset="utf-8"></script>