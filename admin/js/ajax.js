$(document).ready(function(){
	body = $('body');

	function login_validation(){		
         $("#login_form").validate({				     
            submitHandler: function(form) {                
				$(form).ajaxSubmit({
						url:"?",
						data: $(this).serialize(),
						type:"POST",
						timeout: 2000,
						clearForm: false,
						cache: false,
						success: function(){
							console.log('success');
							
						},
						error: function(x, status, error) {
							console.log('Error======');
								
							//console.log('jqXHR' + x);
							//console.log('text status' + status);
							//console.log('error thrown' + error);
							
						},
						statusCode: {
							200: function() {
								console.log('200');
								var feedb_text = $('.feedback_text');
								feedb_text.show().css('color', 'green').text('Logging in..');	
								location.reload();								
								
							},
							403:function(){
								console.log('403');
								var feedb_text = $('.feedback_text');
								feedb_text.show().css('color', 'red').text('Username/Password Wrong, or no Access.');								
							}
						}										
				});
			}
        }); 	
	}// end of login_validation	
	
	
	function edit_validation(){
         $("#edit_form").validate({
            submitHandler: function(form) {
            
		        
				var update_type = $('#update_type').val(); // need to grab the update type to send the correct data
				
				if(update_type === 'pages'){ //if the update type is pages
				
		       		values = ['page_name','page_meta_title','page_meta_keyword','page_template','page_group','sub_page','pages_id','page_order','page_url','token'];
		
					data = new Object; //make data object to hold data passed through post
				
				    for(var i = 0; i <values.length; i++) {
				        data[values[i]] = $('#'+values[i]).val();
				        // == data[page_name] = $('#page_name').val();
				    }
				    					
				}else if(update_type === 'user'){ // if user
					var user_id = $('user_id').val();
					var user_name = $('#user_uname').val();	
					var pass_word = $('#user_pass').val();	
					var full_name = $('#user_fullname').val();	
					var access = $('#add_page_form input[type="radio"]:checked').val(); 
					var update_type = $('#update_type').val();
				 	var token = $('#token').val();
				 	
					data = new Object; //make data object to hold data passed through post
					
					data['user_id'] = user_id;
					data['user_uname'] = user_name;
					data['user_pass'] = pass_word;
					data['user_fullname'] = full_name;
					data['user_access'] = access;
					data['token'] = token;	
					data['update_type'] = update_type;
					
				}
				
				$(form).ajaxSubmit({
						url:"update.php",
						type:"POST",
						data: data,
						timeout: 2000,
						clearForm: false,
						cache: false,
						success: function(){
						console.log('success');
						
							var feedb_text = $('.feedback_text');
							feedb_text.show().css('color', 'green').text('Updated!').stop().fadeOut(2500, "linear");
							
						},
						error: function(x,t,m){
						console.log('failure');

							if(t==="timeout"){
								var feedb_text = $('.feedback_text');
								feedb_text.show().css('color', 'red').text('Something has gone wrong..').stop().fadeOut(2500, "linear");
								
							}
						}
				});
			}
        }); 	
	}// end of edit_validation

	function delete_validation(){	
		data = new Object;
		
		var d_click = $('.delete').click(function(event) {
			$(this).parent().prepend('<div class="yn-overlay"><div class="yesBtn"></div> <div class="noBtn"></div></div>');

			body.on('click', '.yesBtn', function(){
				$(this).parents('form').submit();	
				$('.yn-overlay').remove();		
			});
			
			body.on('click', '.noBtn', function(){
				$('.yn-overlay').remove();		
			});
			
				
				var update_type = $(this).siblings('#type').val();
				var pages_id = $(this).siblings('#id').val();   
				var auth_token = $('#token').val();     
				var db_id = $(this).siblings('#db_id').val();
				
				//make these vars global, however this is terrible..
				data['update_type'] = update_type;
				data['pages_id'] = pages_id;
				data['auth_token'] = auth_token;
				data['db_id'] = db_id;
				
				return false;
		});
		
		$("#delete_form").validate({				     
		    submitHandler: function(form) {                
										
				$(form).ajaxSubmit({
						url:"delete.php",
						type:"POST",
						data: {token: data['auth_token'], id: data['pages_id'], type: data['update_type'], dbid: data['db_id']},

						timeout: 2000,
						clearForm: false,
						cache: false,
						success: function(){
							console.log('good');
							location.reload();
						},
						error: function(x,t,m){
							if(t==="timeout"){
								console.log('timeout');
								
							}
							
							console.log( ' bad: ' + x + m);
						}										
				});
			}
		}); 	
	}// end of delete_validation	

	function add_validation(){	
         $("#add_form").validate({   
            submitHandler: function(form) {
            			 	
				var update_type = $('#update_type').val(); // need to grab the update type to send the correct data
				var added = '';
				
				if(update_type === 'pages'){ //if the update type is pages
				
					values = ['page_name','page_meta_title','page_meta_keyword','page_template','page_group','sub_page','pages_id','page_order','page_url','token', 'update_type'];
		
					data = new Object; //make data object to hold data passed through post
				
				    for(var i = 0; i <values.length; i++) {
				        data[values[i]] = $('#'+values[i]).val();
				        // == data[page_name] = $('#page_name').val();
				    }
				    
					var added = data['page_name'];
					
				}else if(update_type === 'user'){ // if user
					var user_name = $('#user_uname').val();	
					var pass_word = $('#user_pass').val();	
					var full_name = $('#user_fullname').val();	
					var access = $('#add_page_form input[type="radio"]:checked').val(); 
					var update_type = $('#update_type').val();
				 	var token = $('#token').val();
				 	
					data = new Object; //make data object to hold data passed through post
							
					data['user_uname'] = user_name;
					data['user_pass'] = pass_word;
					data['user_fullname'] = full_name;
					data['user_access'] = access;
					data['token'] = token;	
					data['update_type'] = update_type;
					
					var added = data['user_uname'];			
				}
  
            
				$(form).ajaxSubmit({
						url:"add.php",
						type:"POST",
						data: data,
						timeout: 2000,
						clearForm: false,
						cache: false,
						success: function(){
							var feedb_text = $('.feedback_text');
							feedb_text.show().css('color', 'green').text('Added: ' + added + ' !');
							console.log(data);
						},
						error: function(x,t,m){
							if(t==="timeout"){
								var feedb_text = $('.feedback_text');
								feedb_text.show().css('color', 'red').text('Something has gone wrong..');
								
							}
						}
				});
			}
        }); 	
	}// end of edit_validation

	function init(){
		edit_validation();
		login_validation();
		delete_validation();
		add_validation();
	}
	
	init();	
	
});