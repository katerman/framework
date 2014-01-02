<? global $_CONFIG; ?>

<div id="footer">
	<span><a href="https://github.com/katerman/framework">Refined Framework <? echo $_CONFIG->version.  '(' . date('Y') . ')'; ?></a></span>
</div>

<script type="text/javascript" src="<? echo $_CONFIG->js_path; ?>jquery.min.js"></script>
<script type="text/javascript" src="<? echo $_CONFIG->js_path; ?>admin.js" charset="utf-8"></script>
<script type="text/javascript" src="<? echo $_CONFIG->js_path; ?>jquery.validate.min.js"></script>
<script type="text/javascript" src="<? echo $_CONFIG->js_path; ?>jquery.form.js"></script> 
<script type="text/javascript" src="<? echo $_CONFIG->js_path; ?>admin_ajax.js" charset="utf-8"></script>
<script type="text/javascript" src="<? echo $_CONFIG->js_path; ?>responsive-tables.js"></script>
</body>
</html>