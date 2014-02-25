<?php

class appView {
	
	public function show($template, $data = array()) {
		global $admin;
		global $log;
		
		$tpl_debug = false; //show templates!
		
		$path = dirname(__FILE__);
		//$path = str_replace('home3/refinee9/public_html/', '', $path); // this will remove anything from path that shouldnt be there
		
		if($admin){
			$templatePath = dirname($path)."/admin/views/${template}.inc";
		}elseif($log){
			$templatePath = dirname($path)."/admin/log/views/${template}.inc";
		}else{
			$templatePath = $path."/views/${template}.inc";
		}
		
		if ($tpl_debug){
			echo $templatePath . '<br>';
		}
		
		if (file_exists($templatePath)) {
			include_once $templatePath;
		}
	}

}
