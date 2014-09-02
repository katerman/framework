<?php

/**
 * form class - generate quick forms
 */
class Form {
	
    public function __construct($form_name = "form"){
		$this->form_name = $form_name;
    }		
    
    //set
	public function set_FormAction($action){
		$this->form_action = $action;
	}
	
	public function set_FormMethod($method){
		$this->form_method = $method;
	}	
	
	public function set_FormInputs($inputs){
		if(is_array($inputs)){
			$this->form_inputs = $inputs;
		}else{
			echo 'Form.class.php: Please use an array for form inputs.';
		}
	}
    
	//get
	
	public function get_FormName(){
		return $this->form_name;
	}
	
	public function get_FormAction(){
		if(isset($this->form_action)){
			return $this->form_action;
		}else{
			return false;
		}
	}
	
	public function get_FormMethod(){
		if(isset($this->form_method)){
			return $this->form_method;
		}else{
			return false;
		}
	}	
	
	public function get_FormInputs(){
		if(isset($this->form_inputs)){
			return $this->form_inputs;
		}else{
			return false;
		}
	}	
	
	//functions
	
	//create input
	public function makeInput($input){
		$id = isset($input['id']) ? $input['id'] : false;
		$class = isset($input['class']) ? $input['class'] : false;
		$label = isset($input['label']) ? $input['label'] : false;
		
		if($label){
			echo '<label for="';
					echo (isset($id)) ? $id : '';
			echo '">'.$label.'</label>';
		}
		echo '<input class="">';
	}
	
	//create form
	public function createForm(){
		echo '<form id="'.$this->get_FormName().'" method="'.$this->get_FormMethod().'" action="'.$this->get_FormAction().'" accept-charset="utf-8">';
		
		foreach($this->get_FormInputs() as $input){

			switch($input['type']){//check out input types and then have the correct function build out that type of form input
				case 'input':
						$this->makeInput($input);
					break;
					
				case 'checkbox':

					break;
					
				case 'radio':
					
					break;
					
				case 'select':
				
					break;
						
			}
			
		}
		
		echo '</form>';
	}
	
	function makeForm(){
		$this->createForm();
	}
	
	/**
	 * Debug function.
	 * 
	 * @access public
	 * @return void - var dump of this class
	 */	
	public function debug(){
		echo '<div style="border: 1px solid red;"><p style="color:red;">form.class DEBUG:<p> ';	
		var_dump($this);
		echo '</div>';	
	}	
}