(function ($) {
  Drupal.behaviors.chartJS = {
    attach: function (context, settings) {
        $('.chart-container canvas').each( function (index, data) {
            var element_id = $(this).attr('id');
            var ctx = document.getElementById(element_id).getContext("2d");
            var data = settings['chart_' + element_id];
            var options = settings['chart_' + element_id + '_options'];
            switch (settings['chart_' + element_id + '_type']) {
                case 'bar':
                    var myChart = new Chart(ctx).Bar(data, options);
                    break;
                case 'line':
                    var myChart = new Chart(ctx).Line(data, options);
                    break;
            }
        });
    }
  };

})(jQuery);