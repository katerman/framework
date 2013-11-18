$(document).ready(function(){
	var body = $('body');
	var nav_tab = window.location.hash;

	
	function navdropdowns(){
		var fb = $('#nav > ul > li'); //parents
		var allBtns = $('#nav .dropdownBtn li').removeClass('bottomBtnBorder');
		var lastBtn = $('#nav .dropdownBtn li').last().addClass('bottomBtnBorder');
		
		
		fb.click(function(e){
			$(this).next('li').stop().slideToggle();
			
			allBtns;
			lastBtn;
	
		});
		
		$('#nav').find("a[href*='"+nav_tab+"']").click();
		
	}
	

	function content(){
		var content = $('.edit_content');
		var overlay = $('#overlay');
		var add_content = $('.add_content');
		var KEYCODE_ESC = 27;     
		var x = '0'; 
		var update = $('#update_crud');
		var form = $('#content_form');
			
		overlay.on('click', '.form_close', function() { 
	        overlay.hide();
			x = '0';
        });      
        
		content.click(function(e){
			overlay.toggle();
			form.children('h1').text('Edit Content');			
			values = ['content_order','content','content_area','content_name','content_id'];
			update.val('edit');
			
			data = new Object;
			
			for(var i = 0; i <values.length; i++) {
				data[values[i]] = $(this).parents('tr').children('.'+values[i]).text();
				$('#content_form '+'#'+values[i]).val(data[values[i]]);

			}
			
			data['token'] = $(this).parents('tr').children('#content_token').text();
			$('#content_token').val(data['token']);
			
			//console.log(data);
			
			if(x === '0'){
				overlay.append(form);
				x++;
			}
	        
			e.preventDefault();
			
		});
		
		add_content.click(function(){
			overlay.toggle();
			values = ['content_order','content','content_area','content_name','content_id'];
			update.val('add');
			
			data = new Object;
			
			for(var i = 0; i <values.length; i++) {
				$('#content_form '+'#'+values[i]).val('');

			}

			
			form.children('h1').text('Add Content');			
			data = new Object;
			
			
			data['token'] = $('table #content_token').first().text();
			$('#content_token').val(data['token']);
			
			//console.log(data);
			
			if(x === '0'){
				overlay.append(form);
				x++;
			}
	        
			e.preventDefault();

		});
		
		$(document).keyup(function(e) { //clicking escape will hide the overlay and graph 
	        if (e.keyCode == KEYCODE_ESC) {
				overlay.hide();
				x = '0';
	        } 
		});
		

		
		//overlay.click(td);
	}
		

	function templates(){
		var template_edit = $('.edit_template');
		var overlay = $('#overlay');
		var add_template = $('.add_template');
		var KEYCODE_ESC = 27;     
		var x = '0'; 
		var update = $('#update_crud');
		var form = $('#template_form');

		overlay.on('click', '.form_close', function() { 
	        overlay.hide();
			x = '0';
        });      
        
		template_edit.click(function(e){
			overlay.toggle();
			form.children('h1').text('Edit Template');			
			values = ['template_name','id'];
			update.val('edit');
			
			data = new Object;
			
			for(var i = 0; i <values.length; i++) {
				data[values[i]] = $(this).parents('tr').children('.'+values[i]).text();
				$('#template_form '+'#'+values[i]).val(data[values[i]]);
			} 
			
			data['token'] = $(this).parents('tr').children('#template_token').text();
			data['template_type'] = $(this).parents('tr').children('.template_type').text();
			
			var type = data['template_type'];
			if(type === 'page'){
				type = '0';
			}else{
				type = '1';
			}
			
			$('#template_form #template_type').val(type);
			
			//console.log(data['template_type']);
			
			$('#template_form').val(data['token']);
			
			//console.log(data);
			
			if(x === '0'){
				overlay.append(form);
				x++;
			}
	        
			e.preventDefault();
			
		});
		
		add_template.click(function(){
			overlay.toggle();
			values = ['template_name' ,'id'];
			update.val('add');
			
			data = new Object;
			
			for(var i = 0; i <values.length; i++) {
				$('#template_form '+'#'+values[i]).val('');
			}

			
			form.children('h1').text('Add Template');			
			data = new Object;
			
			$('#template_form #template_type').val('0');
				
			data['token'] = $('p#token').text();
			$('#template_token').val(data['token']);
			
			//console.log(data);
			
			if(x === '0'){
				overlay.append(form);
				x++;
			}
	        
			e.preventDefault();

		});
		
		$(document).keyup(function(e) { //clicking escape will hide the overlay and graph 
	        if (e.keyCode == KEYCODE_ESC) {
				overlay.hide();
				x = '0';
	        } 
		});
		

		
		
	}//templates


		
	function init(){
		navdropdowns();
		content();
		templates();
		
		var tables = $('table').addClass('responsive'); // for responsive tables.. yay
		$('#page_template').val($('.page_template').text());
	}
	
	init();
});