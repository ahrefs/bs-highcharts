type t;
[@bs.module] external default: t = "highcharts";

[@bs.module] external data: t => unit = "highcharts/modules/data";
[@bs.module] external heatmap: t => unit = "highcharts/modules/heatmap";
[@bs.module] external boostCanvas: t => unit = "highcharts/modules/boost-canvas";
[@bs.module] external boost: t => unit = "highcharts/modules/boost";


module Options = Highcharts__Options;
