<?php

include_once "../includes/scripts/app.php";

global $dsn, $db_user, $db_pass;//need db info for helpers

$helpers = new helpers($dsn, $db_user, $db_pass);

$config = $helpers->sqlSelect("version" , "config", "");
$config = $config[0];

$current_ver = $config['version'];
$updated = null;
$found = false;
$error = null;

$security = new security();
$token = $security->generateFormToken('token'); 

echo '<input type="hidden" class="hidden token" value="'.$token.'">';

ini_set('max_execution_time',60);
//Check for an update. We have a simple file that has a new release version on each line. (1.00, 1.02, 1.03, etc.)
$getVersions = file_get_contents($_CONFIG->remote_update_loc.'current_version.php') or die ('ERROR');

if ($getVersions != ''){

	//If we managed to access that file, then lets break up those release versions into an array.
	echo '<p>CURRENT VERSION: v'.$current_ver.'</p>';
	echo '<p>Reading Current Releases List</p>';
	$versionList = explode("\\n", $getVersions);
	foreach ($versionList as $aV) {

		if ( $aV > $current_ver) {
			echo '<p>New Update Found: v<span class="new_update">'.$aV.'</span></p>';
			$found = true;

			//Download The File If We Do Not Have It
			if ( !is_file(  $_CONFIG->upload_path.'cms-'.$aV.'.zip' )) {

				echo '<p>Downloading New Update</p>';

				$newUpdate = file_get_contents($_CONFIG->remote_update_loc.'includes/update_files/cms-'.$aV.'.zip');

				if ( !is_dir( realpath($_CONFIG->update_path) ) ) {

					if(mkdir( $_CONFIG->update_path, 0755, true )){
						echo '<p>Missing updates folder, created for you.</p>';
					}
				}

				$dlHandler = fopen($_CONFIG->update_path.'cms-'.$aV.'.zip', 'w');

				if ( !fwrite($dlHandler, $newUpdate) ) {
					echo '<p>Could not save new update. Operation aborted.</p>';
					exit();
				}

				if($dlHandler){
					echo '<p>Update Downloaded And Saved</p>';
				}

				fclose($dlHandler);
				

			}else{
				echo '<p>Update already downloaded.</p>';
			}
			
			if(is_file($_CONFIG->update_path.'cms-'.$aV.'.zip')){
				echo '<button class="btn" id="update_cms">&raquo; Install Update '.$aV.'</button>';
			}else{
				$error = true;
				echo '<p class="error">Update not saved correctly.</p>';
			}

			break;
		}
	}

}else{
	echo '<p>Could not find latest releases.</p>';
}

if($found != true){
	echo '<p class="information">&raquo; No update is available.</p>';
}