
$(document).ready(function() {

  $("#Cornett").fancybox({type: 'ajax'});
  $("#Purvine").fancybox({type: 'ajax'}); 
  $("#Snell").fancybox({type: 'ajax'});
  $("#CollegeUnion").fancybox({type: 'ajax'}); 
  $("#ResidenceHall").fancybox({type: 'ajax'});
  $("#Athletics").fancybox({type: 'ajax'});
  $("#LRC").fancybox({type: 'ajax'});
  $("#Owens").fancybox({type: 'ajax'});
  $("#Semon").fancybox({type: 'ajax'});
  $("#Bovin").fancybox({type: 'ajax'});
  $("#Moehl").fancybox({type: 'ajax'});
  $("#Facilities").fancybox({type: 'ajax'});
  $("#Health").fancybox({type: 'ajax'});
  $("#Dow").fancybox({type: 'ajax'});
  $("#Miller").fancybox({type: 'ajax'});
  $("#VillageOne").fancybox({type: 'ajax'});
  $("#VillageTwo").fancybox({type: 'ajax'});
  $("#VillageThree").fancybox({type: 'ajax'});


jQuery(function($){
var windowWidth = $(window).width();
/*
$(window).resize(function() {
    if(windowWidth != $(window).width()){
    location.reload();
    return;
    }
});*/
$(window).resize(function(){ 
    var width = $(window).width();
    var height = $(window).height();
    var modWidth = '100%';
    
    
    if(width < 1024)
    {
     $('#rightColumn').addClass("hidden");
     $('#leftColumn' ).width( modWidth ).addClass( "mod" );
    }
    else
    {
      $('#rightColumn').removeClass("hidden");
      $('#leftColumn').removeClass("mod");
      $('#leftColumn' ).width( '50%' );
    }
   /* if(windowWidth != $(window).width()){
        location.reload();
    return;
    }*/
 
  });
});
});

var resizeTime = 100;     // total duration of the resize effect, 0 is instant
var resizeDelay = 100;    // time to wait before checking the window size again
                          // the shorter the time, the more reactive it will be.
                          // short or 0 times could cause problems with old browsers.
                          
$('img').mapster({
    mapKey: 'm_campusmapmidHTML'
});

// Resize the map to fit within the boundaries provided

function resize(maxWidth,maxHeight) {
     //maxWidth = document.getElementById("leftColumn").style.maxWidth);
     maxWidth = document.getElementById("leftColumn").offsetWidth;
     var image =  $('img'),
        imgWidth = image.width(),
        imgHeight = image.height(),
        newWidth=0,
        newHeight=0;

    if (imgWidth/maxWidth>imgHeight/maxHeight) {
        newWidth = maxWidth;
    } else {
        newHeight = maxHeight;
    }
    image.mapster('resize',newWidth,newHeight,resizeTime);   
}

// Track window resizing events, but only actually call the map resize when the
// window isn't being resized any more

function onWindowResize() {
    
    var curWidth = $(window).width(),
        curHeight = $(window).height(),
        checking=false;
    if (checking) {
        return;
            }
    checking = true;
    window.setTimeout(function() {
        var newWidth = $(window).width(),
           newHeight = $(window).height();
        if (newWidth === curWidth &&
            newHeight === curHeight) {
            resize(newWidth,newHeight); 
        }
        checking=false;
    },resizeDelay );
}

$(window).bind('resize',onWindowResize);




/*
$('img').mapster({
    fillOpacity: 0.5,
    render_highlight: {
        fillColor: 'ff0000',
        stroke: true,

    },
    fadeInterval: 50,
    mapKey: 'building',
    areas: [
    {
        key: 'Cornett',
        isSelectable: false
    }]
});
*/