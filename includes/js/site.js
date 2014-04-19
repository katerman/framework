$(document).ready(function(){

	//Globals
	var index = null; //index for the Nav
	var window_width = $(window).width();
	
	$(window).resize(function(){ // Generate accurate window size
		window_width = $(window).width();
	});	
	
	$.fn.filterByData = function(prop, val) {
	    return this.filter(
	        function() { return $(this).data(prop)==val; }
	    );
	}
	
	function navdropdowns(){
	
		//#nav.nav-min > ul > li:last-child > ul.dropdown > li
		
		
		
		$('#nav > ul > li:first-child').on('click', function(e){ // Click on top level nav
			
			
			if($(e.target).parents('#nav').hasClass('nav-min')){ //if its in Min nav mode
				
				var the_right_li = $(this).parent().children('li').last();			
				
				if(index != $(e.target).parents('ul').index()){
								
					$('.nav-spot').hide();
					$('.dropdown').hide();
					$('#nav > ul > li:last').hide();
					
					the_right_li.show();
					the_right_li.find('.dropdown').show();
					the_right_li.find('.nav-spot').show();	
													
					e.preventDefault();
					
					
					index = $(e.target).parents('ul').index();
				
				}else{
					

					$('.nav-spot').hide();
					$('.dropdown').hide();
					//$('#nav > ul > li:last').hide();
					
					index = null;
				}
				
				
			}else{ // Regular nav mode
				
				target = $(e.target);
				
				if( target.is('a') || target.is('.fa') ){
					target = $(e.target).parent('li');
				}
					
					
				target.next('li').stop().slideToggle('200');
				target.toggleClass('navBorderBottom');
				target.toggleClass('isSlide');
				
				//console.log(target);
				
				return false;
	
			}
				
		});		
		   
	
				
		$('.search_bg form').on('click','.search_submit',function(e){
		
			if($(this).parents('#nav').hasClass('nav-min')){
				//console.log($(this).prev('.search_field'));
				
				$('body .search_submit_min').toggle();
				
				if(window_width <= 767){
					$(this).prev('.search_field').show();
					$(this).removeClass('nav-min-form-close');
				}else{
					$(this).prev('.search_field').toggle();
					$(this).toggleClass('nav-min-form-close');
				}
				
				e.preventDefault();
				
				
			}
		});
		
		$('nav-min-form-close').on('click', function(e){
			$('#nav').find('.search_submit_min').hide();
		});
		
		
		$('.search_submit_min').on('click',function(e){
			//ajax();
			e.preventDefault();
		});
	
	}
	
	function headerdropdown(){
		var header_bar = $('#header_ul > li'),
			index = null;
		
		header_bar.click(function(){
				
			if(index === $(this).index()) {
				header_bar.find('ul').hide();
				index = null;
			}else{		
				header_bar.find('ul').hide();
				$(this).find('ul').show();
				index = $(this).index();
			}
			
		});
		
		
	}
	
	function extremeform(){
		top_node = $('.top-node');
		child_node = $('.child-node');
		child = $('.child');
		
		top_node.each(function(i,e){
			$(e).data("topNode",i);
		});
		
		child_node.each(function(i,e){
			parentNode = $(e).prevAll('.top-node').data("topNode");
		
			$(e).data("childNode", parentNode );
			$(e).data("myChildren", i );
			
			$(e).addClass('childNode-'+parentNode);
			$(e).addClass('myChildren-'+i);
		});		
		
		child.each(function(i,e){
			parentNode = $(e).prevAll('.child-node').data("myChildren");
			
			$(e).data("child", parentNode );
			
			$(e).addClass('child-'+parentNode);
			
		});
		
			
		//Auto Checkall - or Uncheck all checkboxes
		$('thead .autocheck input').click(function() {  
			if(this.checked) { 
			    $('tbody .autocheck input').each(function() { 
			        this.checked = true;              
			    });
			}else{
			    $('tbody .autocheck input').each(function() { 
			        this.checked = false;                       
			    });         
			}
		});
	    
		
		//top level nodes
		top_node.click(function(){
			
			thisNode = $(this).data('topNode');	
				
			console.log( $(this).data() );

			$(this).siblings('.child-node').filterByData('childNode', thisNode).each(function (index, item) {
			   	$(this).toggle(); 
			});
			
			$(this).nextUntil('.top-node','.child').hide();
			
		});
		
		//2nd level nodes
		child_node.click(function(){
		
			thisNode = $(this).data('childNode');	
			myChildren = $(this).data('myChildren');	
				
			console.log( $(this).data() );

			$(this).siblings('.child').filterByData('child', myChildren).each(function (index, item) {
				$(this).toggle(); 
			});
			
		});	
		
		//child lowest level
		child.click(function(){
			console.log( $(this).data() );
		});
		
	}
	
	
	function slideable(){
		slideable = $('.slideable h1');
		
		slideable.click(function(){
			div = $(this).siblings('div');
			
			div.stop().animate({width: "toggle",height: "toggle"});
		});
	}
	
	function navbarmin(){
		nav = $('#nav');
		controller = $('#nav div.retract-nav .fa');
		
	
		controller.click(function(){
					
			nav.toggleClass('nav-min');
			
			if($(this).parents('#nav').hasClass('nav-min')){ // if the navbar is in min mode
				nav.find('.search_field').hide();
				nav.find('.nav-min-form-close').removeClass('nav-min-form-close');
				
				//#nav.nav-min > ul > li > ul li:last-child:hover:after { border-bottom: none;} 	
				//$('#nav.nav-min > ul > li > .dropdown li:last-child').addClass('noBottomBorder');
				
				nav.find('a.nav-spot').hide();	
				nav.find('.dropdown').hide();	
				
				index = null;
				
				
			}else{ // if the navbar is in normal mode
				nav.find('.search_field').show();
				nav.find('.search_submit_min').hide();		
				nav.find('a.nav-spot').show();	
				nav.find('.dropdown').show();					
				
				$('#nav > ul > li:last-child').hide();
				$('#nav > ul > li:first-child').removeClass('navBorderBottom');
				$('#nav > ul > li:first-child').removeClass('isSlide');
				
			}
			
		});
	
	
	
	}
	
	//for searching filtering search field
	function regexSearch(v, s, m){
		$(s).keyup(function(e) {

			$rows = v;
		    var val =$.trim($(this).val()),
		        reg = RegExp(val, 'i'),
		        text;

		    $rows.show().filter(function(evt) {
		        text = $(this).text().replace(/\s+/g, ' ');
		        return !reg.test(text);
		    }).hide();
		    
			if(m == true && val === ''){
				$('.child-node').hide();
				$('.child').hide();
			}
		    
		});
	}
	
	function hash(){
		if(window.location.hash) {
			var hash = window.location.hash.substring(1); //Puts hash in variable, and removes the # character
			//alert (hash);
			// hash found
		} else {
			// No hash found
		}
	}
	
	function init(){
						
		headerdropdown();
		extremeform(); /*Form node handler*/
		slideable();
		navbarmin();
		navdropdowns();
		hash();
		
/* 		$('.pager-amount').customSelect(); */
		   
	    regexSearch($('.filter-table').parents('.table').find('tbody tr'), $('.filter-table'), true); //what data to filter, what input used to filter, custom parm for dropdown table true will hide all children dropdowns
  
  
   	}
	
	
	
	
	init();



});