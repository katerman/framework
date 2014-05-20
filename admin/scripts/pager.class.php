<?php

include_once "../includes/scripts/app.php";

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
	public function __construct($current, $table, $columns, $amt_key = "amt", $page_key = "page"){
		global $helpers;
		$url = $helpers->url('full');
		
		//if our url params dont have amt (thats the default), then add a param to the url amt=10
		if(isset($_GET[$amt_key])){
			$this->amount = $_GET[$amt_key]; //set $this->amount to our url param
			$this->amt_key = $amt_key; //reusable the class now knows what our amount key is, letting us have more than one pager per page
		}else{
			$helpers->setParam($url,$amt_key, 10,true);
		}
		
		//same as above but for page url param
		if(isset($_GET[$page_key])){
			$this->page = $_GET[$page_key];
			$this->page_key = $amt_key;
		}else{
			$helpers->setParam($url,$page_key, 1,true);
		}
		
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
		return ceil($count / $this::getAmount());
	}

	/**
	 * getLimit function.
	 * 
	 * @access public
	 * @return $limit if page is not 0 - 
	 * @info this determines our limit for paging, basically what row in the DB will we need on whatever page.
	 */
	public function getLimit(){
		if($this::getPage() == 1){
			return 0;
		}else{
			$limit = $this::getPage() - 1;
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
			<div class="pager">
				<p>Page</p>
				<div class="pager-back fa fa-arrow-left"></div>
				<input type="text" value="'.$this::getPage().'" class="pager-input">
				<div class="pager-forward fa fa-arrow-right"></div>
				<p> of
					<span class="pager-max">'.$this::getTotal().'</span>
				</p>


				<p>Show</p>

				<select class="pager-amount">';
				
				//using our $this->dropdown_values this foreach will populate text and values
				foreach($this->dropdown_values as $text=>$value){
					echo '<option value="'.$value.'"'.($value == $this::getAmount() ? "selected" : "").'>'.$text.'</option>';
				}

		echo '
				</select>

				<p>rows</p>
			</div>
		';
	}


	/**
	 * ShowPaging function.
	 * 
	 * @access public
	 * @return void - this shows paging elements, customize how it looks in paging_html()
	 */
	public function ShowPaging(){
		$this::paging_html();
	}

	/**
	 * getTableData function.
	 * 
	 * @access public
	 * @return void - Using the inputted table and columns provided, and an settable getTableSqlDataWhere(), this function will return a PDO object with data from the DB, but paged out.
	 */
	public function getTableData(){
		global $helpers;	
		$query = $helpers->sqlSelect($this->sql['columns'], $this->sql['table'],"", $this::getTableSqlDataWhere().' LIMIT '.$this::getLimit().','. $this::getAmount());
		//print_r('Start from this row #: '.$this::getLimit().', Limit to this amount of rows: '. $this::getAmount());
		return $query;
	}


}