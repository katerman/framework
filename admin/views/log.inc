<?php
if($perms['users'] == 1){

	//pager
	$amt = $helpers->getQuery('amt','return');
	include_once "scripts/pager.class.php"; //include this class where needed

	global $helpers;
	
	//$log = $helpers->sqlSelect("*" , "log", "", "");

	$token = $security->generateFormToken('token'); 
	
	$pager = new pager($amt, 'log', '*');  
	$pager->setTableSqlDataWhere("ORDER BY log_id DESC");

?>


<h1>The Log</h1>

<a id="purge" class="btn" style="margin: 5xp 0;">Purge The Log</a>
<input type="hidden" class="token" value="<?php echo $token; ?>">

<table class="search_table table" style="margin-top: 10px;">
	<thead>
		<tr>
			<td class="vis-hidden"></td>
			<td><input class="search" placeholder="Type to Filter"/></td>
		</tr>
		<tr>
			<td>Name</td>
			<td>Action</td>
			<td>Content</td>
			<td>Time</td>
		</tr>
	</thead>
	
	
	<tbody>
		<?
			foreach($pager->getTableData() as $l){
				echo '<tr class="data"><td>'.$l['log_name'].'</td>';
				echo '<td>'.$l['log_action'].'</td>';
				echo '<td>'.$l['log_content'].'</td>';
				echo '<td>'.$l['log_time'].'</td></tr>';
				
			}
		?>
	</tbody>
</table>

	

<?php
		$pager->ShowPaging();
	}else{
		header('Location: ?tpl=default_view');
	}