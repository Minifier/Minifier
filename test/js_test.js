/*******************************************************************
Copyright (C) 2018 Oscar MARIE--TAILLEFER   <o5mariet@enib.fr>
Copyright (C) 2018 Nils JEGOU-GERGAUD       <n5jegoug@enib.fr>
Copyright (C) 2018 Nicols FRANCIS           <n4franci@enib.fr>
Copyright (C) 2018 Corentin LAMBERT         <c4lamber@enib.fr>
This file is part of Minifier.
Minifier is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
Minifier is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with Minifier.  If not, see <http://www.gnu.org/licenses/>.
*******************************************************************/
$(function(){
  var formContact = $('.contact_div');
  var formNewsletter = $('.newslettre_div');
  var sub_staff = $('.sub_staff');
  var slideDuration = "800" ;
  var sub_videos = $('.sub_videos');

  $.resize_windows = function(){
    var width_windows= $('body').width();
    var grande_card = $(".btn-grande");
    var moyen_card = $(".btn-moyenne");

    if (width_windows > 1280){
      $.showThis(grande_card);
      $.hideThis(moyen_card);
    }
    else{
      if (800 < width_windows <= 1280) {
        $.hideThis(grande_card);
        $.showThis(moyen_card);
      }
    }
  };

  $.hideThis = function(elem){
    elem.slideUp(slideDuration).trigger('formVisible');
  };

  $.showThis = function(elem){
    elem.slideDown(slideDuration).trigger('formVisible');

  }

  $.scrollToElement = function(elem){
    $('html, body').animate
    ({
      scrollTop: elem.offset().top
    }, slideDuration);
  };

  $('header a:nth-child(2)').click(function(){
    if(sub_videos.is(':visible'))
    {
      sub_videos.slideUp(slideDuration, function()
      {
        sub_staff
        .slideDown(slideDuration);
      });
    } else
    {
      if(sub_staff.is(':visible'))
      {
        sub_staff.slideUp(slideDuration);
      }else
      {
        sub_staff
        .slideDown(slideDuration);
      }
    }
  });

  $('header a:nth-child(4)').click(function(){
    if(sub_staff.is(':visible'))
    {
      sub_staff.slideUp(slideDuration, function()
      {
        sub_videos
        .slideDown(slideDuration);
      });

    } else
    {
      if(sub_videos.is(':visible'))
      {
        sub_videos.slideUp(slideDuration);
      }else
      {
        sub_videos
        .slideDown(slideDuration);
      }
    }
  });

  $('.contact_click').click(function(){
    if(formNewsletter.is(':visible'))
    {
      formNewsletter.slideUp(slideDuration, function()
      {
        formContact
        .slideDown(slideDuration)
        .trigger('formVisible');
      }).trigger('formVisible');

    } else
    {
      if(formContact.is(':visible'))
      {
        formContact.slideUp(slideDuration).trigger('formVisible');;
      }else
      {
        formContact
        .slideDown(slideDuration)
        .trigger('formVisible');
      }
    }
  });

  $(".newslettre_click").click(function(){
    if(formContact.is(':visible'))
    {
      formContact.slideUp(slideDuration, function()
      {
        formNewsletter
        .slideDown(slideDuration)
        .trigger('formVisible');
      }).trigger('formVisible');;

    } else
    {
      if(formNewsletter.is(':visible'))
      {
        formNewsletter.slideUp(slideDuration).trigger('formVisible');;
      }else
      {
        formNewsletter
        .slideDown(slideDuration)
        .trigger('formVisible');
      }
    }
  });

  $.display_video = function () {

    $('.frame').click(function (){
      $('.frame').css("display","none");
      $('.frame_video').css("display","none");
    });

    $('.video_nb_1').click( function(){
      $('.frame').css("display","block");
      $('#video_pres').css("display","block");
    });

    $('.video_nb_2').click( function(){
      $('.frame').css("display","block");
      $('#video_cumalott').css("display","block");
    });


    $('.video_nb_3').click( function(){
      $('.frame').css("display","block");
      $('#video_dhukaca').css("display","block");
    });

    $('.video_nb_4').click( function(){
      $('.frame').css("display","block");
      $('#video_malomorice').css("display","block");
    });

    $('.video_nb_5').click( function(){
      $('.frame').css("display","block");
      $('#video_chasse').css("display","block");
    });

    $('.video_nb_6').click( function(){
      $('.frame').css("display","block");
      $('#video_waf').css("display","block");
    });
  };

  $.sub_title_show = function(){
    $('.sub_picture').mouseout(function(){
      $(".sub_title").text('De quelle personne voulez-vous la description ?');
    });

    $('.p1').mouseover(function(){
      $(".sub_title").text('Alex ?');
    });
    $('.p2').mouseover(function(){
      $(".sub_title").text('Elie ?');
    });
    $('.p3').mouseover(function(){
      $(".sub_title").text('Caillard ?');
    });
    $('.p4').mouseover(function(){
      $(".sub_title").text('Caron ?');
    });
    $('.p5').mouseover(function(){
      $(".sub_title").text('Flo ?');
    });
    $('.p6').mouseover(function(){
      $(".sub_title").text('Guillaume ?');
    });
    $('.p7').mouseover(function(){
      $(".sub_title").text('Malo ?');
    });
    $('.p8').mouseover(function(){
      $(".sub_title").text('Oscar ?');
    });
    $('.p9').mouseover(function(){
      $(".sub_title").text('Poulain ?');
    });
  };

  formContact.on('formVisible', function(){

    $.scrollToElement($(".contact"));
  });

  formNewsletter.on('formVisible', function(){

    $.scrollToElement($(".contact"));
  });

  sub_staff.on('formVisible' , function(){
    $.scrollToElement($(".title"));
  })

  sub_videos.on('formVisible' , function(){
    $.scrollToElement($('.title'));
  });

  $(window).resize( function(){
    $.resize_windows();
    $('.arrow_staff').css('left',$(".btn-staff").offset().left+$('.btn-staff').width()/2-$('.arrow_staff').width()/2);
    $('.arrow_videos').css('left',$(".btn-videos").offset().left+$('.btn-videos').width()/2-$('.arrow_videos').width()/2);
  });

  $(window).ready( function(){
    $.resize_windows();
    $(".sub_title").text('De quelle personne voulez-vous la description ?');
    $('.arrow_staff').css('left',$(".btn-staff").offset().left+$('.btn-staff').width()/2-$('.arrow_staff').width()/2);
    $('.arrow_videos').css('left',$(".btn-videos").offset().left+$('.btn-videos').width()/2-$('.arrow_videos').width()/2);

    $.sub_title_show();
    $.display_video();
  });

})
