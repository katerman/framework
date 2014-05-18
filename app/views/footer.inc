<?php  
	global $config; 	
	global $_CONFIG;
?>

<script src="//ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js"></script>
<script src="<?php echo $_CONFIG->js_path ?>jquery.validate.min.js" charset="utf-8"></script>
<script src="<?php echo $_CONFIG->js_path ?>jquery.form.js" charset="utf-8"></script>
<script src="<?php echo $_CONFIG->js_path ?>site.js" charset="utf-8"></script>
<script src="<?php echo $_CONFIG->js_path ?>ajax.js" charset="utf-8"></script>

<!-- bootsrap -->
<script src="//netdna.bootstrapcdn.com/bootstrap/3.1.1/js/bootstrap.min.js"></script>

<script>
	<?php echo $config['extra_js'];?>
</script>
</body>
</html>