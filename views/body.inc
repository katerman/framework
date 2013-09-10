<?php
	echo 'full: ' . helpers::url(full) . '<br>';
	echo 'fullpage: ' . helpers::url(fullpage) . '<br>';
	echo 'folder: ' . helpers::url(folder) . '<br>';
	echo 'base: ' . helpers::url(base);
?>


<div id="content"><!-- start content -->
<h1><? echo helpers::url(base); ?></h1>
<p>Welcome back, <?php echo htmlentities($data['fullname']);?>.</p>
<p><a class="logout" href="logout.php">Log out</a></p>

</div><!-- end content-->

<script src="//ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js"></script>

