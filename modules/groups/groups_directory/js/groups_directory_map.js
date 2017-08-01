(function ($) {

  /**
   * For leafleat API docs, see:
   * http://leafletjs.com/reference.html
   **/

  var cnt = 0;
  // Attach to Leaflet object via its API
  $(document).bind('leaflet.feature', function(e, lFeature, feature) {
    // Remove default click event (infoWindow Popup) and add our own
    if (feature.label) {
      var contents = feature.contents;
      lFeature.on('click', function() {
        var img = $(lFeature._icon);
        img.addClass('active').siblings().removeClass('active');
        redirectMarkerURL(feature);
      });
      lFeature.unbindPopup();
      cnt++;
    }
  });

  function redirectMarkerURL(marker) {
    window.top.location.href = marker.popup;
  }

})(jQuery);
