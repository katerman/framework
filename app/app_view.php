<?php

class appView {

	public function show($template, $data = array()) {
		global $admin;
		global $log;
		global $_CONFIG;

		$tpl_debug = $_CONFIG->template_debug; //show templates!

		$path = dirname(__FILE__);
		//$path = str_replace('home3/refinee9/public_html/', '', $path); // this will remove anything from path that shouldnt be there

		if($admin){
			$templatePath = $_CONFIG->admin_template_path."${template}.inc";
		}else{
			$templatePath = $_CONFIG->current_theme_path."${template}.inc";
		}

		if ($tpl_debug){
			echo $templatePath . '<div style="border: 1px dashed red;"><br>';
		}

		if (file_exists($templatePath)) {
			include_once $templatePath;
		}

		if($tpl_debug){
			echo '</div>';
		}
	}

	public function show_content($content){
		global $areas;
		if(isset($areas->$content)){echo $areas->$content; }
	}

	public function show_label($label){
		global $labels;
		if(isset($labels->$label)){echo $labels->$label; }
	}

}
