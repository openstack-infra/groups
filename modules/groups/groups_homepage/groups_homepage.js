/**
 * Relocate html map pinpoints based on lat and long data.
 */
(function($) {
  Drupal.behaviors.groups_homepage = {
    attach : function(context) {
      console.log("ready!");
      var communityMap = $("#community-map");
      communityMap.find(".community-map-pin").each(function() {
        var lat = new Number($(this).find("span.latitude").text());
        var lng = new Number($(this).find("span.longitude").text());
        longPx = ((communityMap.width()/360) * (180 + lng));
        latPx = ((communityMap.height()/180) * (90 - lat));
        $(this).css('top', latPx + "px");
        $(this).css('left', longPx + "px");
      });
    }
  }
})(jQuery);