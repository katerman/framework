<?php

/**
 * Table Class - Generate tables with a wide array of settings
 */
class Table {
	    
    //set
	public function set_TableStrLen($strln){
		$this->table_StrLen = $strln;
	}
	
	public function set_TableId($id){
		$this->table_id = $id;
	}
	
	public function set_TableHead($array){
		$this->table_head = (array)$array;
	}
	
	public function set_TableRows($array){
		$this->table_rows = (array)$array;
	}   
	
	public function set_TableClass($class){
		$this->table_class = $class;
	}
	
	public function set_TableActions($actions){
		$this->actions = $actions;
	}	 
	
	public function set_Token($token){
		$this->token = $token;
	}	
	
	public function set_ToolTip($set){
		$this->tooltip = $set;
	}
	    
    //get	
	public function get_TableClass(){
		if(isset($this->table_class)){
			return $this->table_class;		
		}else{
			return '';
		}
	}	

	public function get_TableId(){
		if(isset($this->table_id)){
			return $this->table_id;		
		}else{
			return '';
		}
	}		

	public function get_TableRows(){
		return $this->table_rows;
	}

	public function get_TableHead(){
		return $this->table_head;
	}

	public function get_TableStrLen(){
		if(isset($this->table_StrLen)){
			return $this->table_StrLen;		
		}else{
			return 99999;
		}	
	}

	public function get_TableActions(){
		if(isset($this->actions)){
			return $this->actions;		
		}else{
			return false;
		}	
	}	

	public function get_Token(){
		if(isset($this->token)){
			return $this->token;		
		}else{
			return false;
		}	
	}		
	
	public function get_ToolTip(){
		if(isset($this->tooltip)){
			return $this->tooltip;		
		}else{
			return false;
		}	
	}
		
	public function make_Table(){
		
		$table_head = $this->get_TableHead();	
		$table_rows = $this->get_TableRows();	
		$actions = $this->get_TableActions();
		
		$id = $this->get_TableId();
		$class = $this->get_TableClass();
		$token = $this->get_Token();
		$tooltip = $this->get_ToolTip();
		
		$len = $this->get_TableStrLen();
		
	
		echo "<table id='$id' class='$class'><thead><tr>";
		if(!isset($table_head)){
			die('Please set table heads');
		}		
		foreach($table_head as $key=>$head){
			echo "<td>$key</td>";
		}
		
		if($actions){
			echo '<td>Actions</td>';
		}
		
		echo "</tr><tbody>";
		if(!isset($table_rows) ){
			die('Please set table rows');
		}
		
		
		foreach($table_rows as $key=>$row){
			echo "<tr>";
			$i = 1;
			foreach($table_head as $hkey=>$head){
				
				echo "<td>".trim_text($row[$head], $len)."</td>";
				
				if($tooltip){
					echo '<div class="hidden search tooltip">' . $row[$head] . '</div>';
				}
			
				$count = count($table_head);

				if($i % $count == 0 && $actions){
					if(is_array($actions)){
						echo '<td style="position: relative;">';
						foreach($actions as $key=>$action){
							
							switch($key){
								case 'link':
									echo '<a class="edit pull-left" href="'.$action['query'].'"></a>';
									break;
								case 'view':
									echo '<a class="edit pull-left" href="'.$action['query'].$row[$action['id']].'"></a>';
									break;
								case 'delete':
									if($this->get_Token()){
										echo '
											<form class="pull-left delete_form" action="" method="">
												<a class="delete" href="?id='.$row[$action['id']].'"></a>
												<input type="hidden" name="token" id="token" value="'.$token .'">
												<input id="id" type="hidden" value="'. $row[$action['id']] .'"/>
												<input id="type" type="hidden" value="'.$action['table_name'].'"/>
												<input id="db_id" type="hidden" value="'.$action['id'].'"/>
												<input class="hidden" type="submit" id="submit"/>
											</form>		
										';
										
									}else{
										die('You need a token to delete things, please set a token using $table->set_Token($token)');
									}
									break;				
														
							}
						}				
						echo '</td>';
					}else{
						die('Actions needs to be an array');
					}

				}		
				$i++;		
			}		
			
			echo "</tr>";
		}		
		
		echo "</tbody></table>";
				
	}
	
	function debug(){
		echo '<div style="border: 1px solid red;"><p style="color:red;">table.class DEBUG:<p> ';	
		var_dump($this);
		echo '</div>';	
	}
  
}

