<?php

class Pager {
	
	/**
	 * __construct function.
	 * 
	 * @access public
	 * @param mixed $current - usually going to be a $_GET[] of your $amt_key, your current page
	 * @param mixed $table - the pager app is going to do some sql for you, for ease. Put in whatever table you want data outputted later
	 * @param mixed $columns - for sql input what columns you'll need
	 * @param string $amt_key (default: "amt") - the url query you'll be using for paging, customizable so you can have more than one
	 * @param string $page_key (default: "page") - url query for page customizable
	 */
	public function __construct($current = null, $table = null, $columns = null, $amt_key = "amt", $page_key = "page"){
		global $helpers;
		$url = $helpers->url('full');
		
		$this->sql = array(
			"table" => $table,
			"columns" => $columns
		);
		
		$this->dropdown_values = array(
			"10" => "10",
			"20" => "20",
			"30" => "30",
			"All" => "1000"
		);
				
		//if our url params dont have amt (thats the default), then add a param to the url amt=10
		if(isset($_GET[$amt_key])){
			$this->amount = $_GET[$amt_key]; //set $this->amount to our url param
			$this->amt_key = $amt_key; //reusable the class now knows what our amount key is, letting us have more than one pager per page
		}else{
			$amt_key ? $this->amt_key = $amt_key : $this->amt_key = null ;
			$this->amount = key($this->dropdown_values);
		}
		
		//same as above but for page url param
		if(isset($_GET[$page_key])){
			$this->page = $_GET[$page_key];
			$this->page_key = $page_key;
		}else{
			$page_key ? $this->page_key = $page_key : $this->page_key = null ;
			$this->page = 1;
		}		
		
		$this->tableWhere = '';

	}
	
	/**
	 * setDropDownValues function.
	 * 
	 * @access public
	 * @param array $dd (default: array())
	 * @return void -this will set what values the pagnation drop downs will have
	 */
	public function setDropDownValues($dd = array()){
		$this->dropdown_values = $dd;
	}

	/**
	 * getAmount function.
	 * 
	 * @access public
	 * @return void - get the query for amount per page (10,20,30,all)
	 */
	public function getAmount(){
		return $this->amount;
	}

	/**
	 * getPage function.
	 * 
	 * @access public
	 * @return void - returns what page # you're on
	 */
	public function getPage(){
		return $this->page;
	}
	
	/**
	 * setTableSqlDataWhere function.
	 * 
	 * @access public
	 * @param mixed $where
	 * @return void - if you need to add extra to the end of your sql statement you'll use this.
	 */
	public function setTableSqlDataWhere($where){
		$this->tableWhere = $where;
	}
	
	/**
	 * setShowPagerWhereNoData function.
	 * 
	 * @access public
	 * @param mixed $bool
	 * @return void - used to hide the pager if there is no data, why waste screen space?
	 */
	public function setShowPagerWhereNoData($bool){
		$this->ShowPagerWhereNoData = (bool)$bool;
	}
	
	/**
	 * getShowPagerWhereNoData function - get what the value of showPagerWhereNoData is
	 * 
	 * @access public
	 * @return - false if its not set, whatever value it is if it is set.
	 */
	public function getShowPagerWhereNoData(){
		if(isset($this->ShowPagerWhereNoData)){
			return $this->ShowPagerWhereNoData;
		}else{
			return null;
		}
	}
	
	/**
	 * getTableSqlDataWhere function.
	 * 
	 * @access public
	 * @return - returns what you set for setTableSqlDataWhere()
	 */
	public function getTableSqlDataWhere(){
		if(isset($this->tableWhere)){
			return $this->tableWhere;
		}
	}	

	/**
	 * getTotal function.
	 * 
	 * @access public
	 * @return's how many pages we have as a max
	 */
	public function getTotal(){
		global $helpers;
		if(isset($this->tableWhere)){
			$where = $this->tableWhere;
		}else{
			$where = "";
		}

		$count = count($helpers->sqlSelect($this->sql['columns'], $this->sql['table'] ,"", $where));
		if($count == 0){return 1;}
		return ceil($count / $this->getAmount());
	}

	/**
	 * getLimit function.
	 * 
	 * @access public
	 * @return $limit if page is not 0 - 
	 * @info this determines our limit for paging, basically what row in the DB will we need on whatever page.
	 */
	public function getLimit(){
		if($this->getPage() == 1 || $this->getPage() <= 0){
			return 0;
		}else{
			$limit = $this->getPage() - 1;
			return $limit;
		}
	}

	/**
	 * paging_html function.
	 * 
	 * @access public
	 * @return void - the custom html our pager uses.
	 */
	public function paging_html(){
		
		echo '
			<script>
				var array = ["'.$this->page_key.'","'.$this->amt_key.'"]
				pager_array.push(array);
			</script>';
		
		echo '
			<div class="pager" id="pager-'.$this->page_key.'">
				<p>Page</p>
				<div class="pager-back fa fa-arrow-left"></div>
				<input type="text" value="'.$this->getPage().'" class="pager-input">
				<div class="pager-forward fa fa-arrow-right"></div>
				<p> of
					<span class="pager-max">'.$this->getTotal().'</span>
				</p>


				<p>Show</p>

				<select class="pager-amount">';
				
				//using our $this->dropdown_values this foreach will populate text and values
				foreach($this->dropdown_values as $text=>$value){
					echo '<option value="'.$value.'"'.($value == $this->getAmount() ? "selected" : "").'>'.$text.'</option>';
				}

		echo '
				</select>

				<p>rows</p>
			</div>
		';
	}

	/**
	 * getTableData function.
	 * 
	 * @access public
	 * @return void - Using the inputted table and columns provided, and an settable getTableSqlDataWhere(), this function will return a PDO object with data from the DB, but paged out.
	 */
	public function getTableData(){
		global $helpers;	
		$query = $helpers->sqlSelect($this->sql['columns'], $this->sql['table'],"", $this->getTableSqlDataWhere().' LIMIT '.$this->getLimit().','. $this->getAmount());
		//print_r('Start from this row #: '.$this->getLimit().', Limit to this amount of rows: '. $this->getAmount());
		return $query;
	}
	
	/**
	 * ShowPaging function.
	 * 
	 * @access public
	 * @return void - this shows paging elements, customize how it looks in paging_html()
	 */
	public function ShowPaging(){
		if($this->getShowPagerWhereNoData() == true && count($this->getTableData()) == 0){
			
		}else{
			$this->paging_html();
		}
	}	
	
	/**
	 * Debug function.
	 * 
	 * @access public
	 * @return void - var dump of this class
	 */	
	public function debug(){
		echo '<div style="border: 1px solid red;"><p style="color:red;">pager.class DEBUG:<p> ';	
		var_dump($this);
		echo '</div>';	
	}	


}