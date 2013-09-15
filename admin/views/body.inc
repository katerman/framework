<?php
/*
	echo 'full: ' . helpers::url(full) . '<br>';
	echo 'fullpage: ' . helpers::url(fullpage) . '<br>';
	echo 'folder: ' . helpers::url(folder) . '<br>';
	echo 'base: ' . helpers::url(base) . '<br>';
	echo 'lastpath: ' . helpers::url(lastpath);
*/


?>


<div id="content"><!-- start content -->
<h1><? echo helpers::url(base); ?></h1>
<p>Welcome back, <?php echo htmlentities($data['fullname']);?>.</p>
<p><a class="logout" href="logout.php">Log out</a></p>
<p><? global $model; $model->sqlPages(); ?> <? /* Yeah, you are including, so all vars are available in here...  I mean, it'sd not the best way, but because of it, you CAN do  */ ?></p>
</div><!-- end content-->

<script src="//ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js"></script>
