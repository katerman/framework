<?php

//Misc Functions

function print_pre ($expression, $return = false, $wrap = false){
	$css = 'border:1px dashed #06f;background:#69f;padding:1em;text-align:left;';
	if ($wrap) {
		$str = '<p style="' . $css . '"><tt>' . str_replace(
			array('  ', "\n"), array('&nbsp; ', '<br />'),
			htmlspecialchars(print_r($expression, true))
		) . '</tt></p>';
	} else {
		$str = '<pre style="' . $css . '">'
			. htmlspecialchars(print_r($expression, true)) . '</pre>';
	}
	if ($return) {
		if (is_string($return) && $fh = fopen($return, 'a')) {
			fwrite($fh, $str);
			fclose($fh);
		}
		return $str;
	} else
		echo $str;
}