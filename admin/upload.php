<?php
//need more custom here.

$ds          = DIRECTORY_SEPARATOR;  
 
$storeFolder = 'uploads';   
 
if (!empty($_FILES)) {
     
    $tempFile = $_FILES['file']['tmp_name'];                    
      
    $targetPath = dirname(dirname(__FILE__)) . $ds. $storeFolder . $ds;  
     
    $targetFile =  $targetPath. $_FILES['file']['name'];  
 
    move_uploaded_file($tempFile,$targetFile); 
    
     
}

//echo ''.dirname(dirname(__FILE__)) . $ds. $storeFolder . $ds;
