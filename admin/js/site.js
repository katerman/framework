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
	

	function edit_content(){
		var content = $('.edit_content');
		var overlay = $('#overlay');
		var KEYCODE_ESC = 27;     
		var x = '0'; 
		
		overlay.on('click', '.form_close', function() { 
	        overlay.hide();
			x = '0';
        });      
        
		content.click(function(e){
			var form = $('#edit_content_form');
			overlay.toggle();
			
			values = ['content_order','content','content_area','content_name','content_id'];
			
			data = new Object;
			
			for(var i = 0; i <values.length; i++) {
				data[values[i]] = $(this).parents('tr').children('.'+values[i]).text();
				console.log($('#edit_content_form '+'#'+values[i]).val(data[values[i]]));

			}
			
			data['token'] = $(this).parents('tr').children('#content_token').text();
			$('#content_token').val(data['token']);
			
			console.log(data);
			
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
		
		$('#edit_content_form').on("submit", function() { 
			console.log('submitted line 60 site dot js');
		});
		

		
		//overlay.click(td);
	}
	
	function init(){
		navdropdowns();
		edit_content();
	}
	
	init();
});