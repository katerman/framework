<?php

include_once "../../includes/scripts/app.php";

global $dsn, $db_user, $db_pass;//need db info for helpers

$helpers = new helpers();

$security = new security();
$security->checkToken('token');  // check security token

$config = $helpers->sqlSelect("version" , "config", "", "");
$config = $config[0];

$current_ver = $config['version'];
$updated = null;
$error = null;
$aV = $_POST['new_update_num'];

$data = array();
$msg = null;
$loop = 0;

//Open The File And Do Stuff
$zipHandle = zip_open($_CONFIG->update_path.'cms-'.$aV.'.zip');

if(!$zipHandle){
	$msg = '<p style="color: red;">Could not find .zip of new release.. exiting</p>';
	$error = true;
}

while ($aF = zip_read($zipHandle) ){

	// if($error == true){break;}

	$thisFileName = zip_entry_name($aF);
	$thisFileDir = dirname($thisFileName).'/';

	//Continue if its not a file
	if ( substr($thisFileName,-1,1) == '/') {
		continue;
	}

	if(!preg_match('/__MACOSX|.DS_Store|\.\_|\.\//', $thisFileName)){//OSX work around for regular zip files.
		//Make the directory if we need to...
		if ( !is_dir( $_CONFIG->config_path.$thisFileDir ) ){
			if(!mkdir( $_CONFIG->config_path.$thisFileDir, 0755, true )){
				$msg = '<p class="error">Could not create directory: '.$_CONFIG->config_path.$thisFileDir.' Exiting</p>';
				$error = true;
			}
			$msg = '<p>Created Directory '.$thisFileDir.'</p>';
		}

		//Overwrite the file
		if ( !is_dir($_CONFIG->config_path.$thisFileName) ) {
			
			$data['files'][$loop]['name'] = $thisFileName;
			
			$contents = zip_entry_read($aF, zip_entry_filesize($aF));
			$pieces = explode(".", $thisFileName);
			if ($pieces[1] != 'png' && $pieces[1] != 'jpg' && $pieces[1] != 'gif') {
				$contents = str_replace("\r\n", "\n", $contents);
			}
			$updateThis = '';

			//If we need to run commands, then do it.
			if ( $thisFileName == 'patch.php' ){
				$upgradeExec = fopen('patch.php','w');
				fwrite($upgradeExec, $contents);
				fclose($upgradeExec);
				include ('patch.php');
				unlink('patch.php');
			
				$data['files'][$loop]['status'] = 'Executed';
				$loop++;
			}else{

				$updateThis = fopen($_CONFIG->config_path.$thisFileName, 'w');

				if(fwrite($updateThis, $contents)){
					$data['files'][$loop]['status'] = 'Updated';
					fclose($updateThis);
				}else{
					$data['files'][$loop]['progress'] = 'Failed';
				}
				
				
				
				unset($contents);

				$loop++;
			}
		}
	}
}

$updated = TRUE;


if ($updated == true && $error != true){
	//set_setting('site','CMS',$aV);
	$msg .= '<p class="success">&raquo; CMS Updated to v'.$aV.'</p>';
}

$data['message'] = $msg;

echo json_encode($data);
