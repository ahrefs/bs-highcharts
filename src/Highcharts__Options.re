module Data = {
  type t;
  /** Creates a Data.t value */
  [@bs.obj]
  external make: (~csv: string=?, unit) => t = "";
};

module Chart = {
  type t;
  /** Creates a Chart.t value */
  [@bs.obj]
  external make:
    (
      ~margin: (int, int, int, int)=?,
      ~marginTop: int=?,
      ~marginRight: int=?,
      ~marginBottom: int=?,
      ~marginLeft: int=?,
      ~spacing: (int, int, int, int)=?,
      ~spacingTop: int=?,
      ~spacingRight: int=?,
      ~spacingBottom: int=?,
      ~spacingLeft: int=?,
      unit
    ) =>
    t =
    "";
};

module Boost = {
  type t;
  /** Creates a Boost.t value */
  [@bs.obj]
  external make: (~useGPUTranslations: bool=?, unit) => t = "";
};

module Tooltip = {
  type t;
  /** Creates a Tooltip.t value.
    Note: this is not the same type as the tooltip property inside a series.
   */
  [@bs.obj]
  external make:
    (
      ~borderColor: string=?,
      ~formatter: [@bs.this] (
                    {
                      .
                      "point": {
                        .
                        "x": int,
                        "y": int,
                        "value": int,
                      },
                    } =>
                    string
                  )
                    =?,
      ~headerFormat: string=?,
      ~pointFormat: string=?,
      ~useHTML: bool=?,
      unit
    ) =>
    t =
    "";
};

module Series = {
  type t;
  /** Creates a `line` series */
  [@bs.obj]
  external line: (~_type: [@bs.as "line"] _, ~data: array(int), unit) => t =
    "";
  /** Creates a `heatmap` series */
  [@bs.obj]
  external heatmap:
    (
      ~_type: [@bs.as "heatmap"] _,
      ~boostThreshold: int=?,
      ~borderWidth: int=?,
      ~colsize: int=?,
      ~data: array(array('a))=?,
      ~nullColor: string=?,
      ~turboThreshold: float=?,
      unit
    ) =>
    t =
    "";
};

module CssObject = {
  type t;
  /** Creates a CssObject.t value */
  [@bs.obj]
  external make: (~color: string=?, ~fontSize: string=?, unit) => t = "";
};

module Title = {
  type t;
  /** Creates a CssObject.t value.
    Note this is the chart title, which has a different type than the axis title.
   */
  [@bs.obj]
  external make:
    (
      ~align: [@bs.string] [ | `left | `center | `right]=?,
      ~style: CssObject.t=?,
      ~text: option(string), // text: undefined is needed to hide the title: https://api.highcharts.com/highcharts/yAxis.title.text
      ~x: int=?,
      ~y: int=?,
      unit
    ) =>
    t =
    "";
};

module AxisLabel = {
  type t;
  /** Creates an AxisLabel.t value */
  [@bs.obj]
  external make:
    (
      ~align: [@bs.string] [ | `left | `center | `right]=?,
      ~format: string=?,
      ~formatter: [@bs.this] (
                    {
                      .
                      "value": float,
                      "isFirst": bool,
                      "isLast": bool,
                    } =>
                    string
                  )
                    =?,
      ~style: CssObject.t=?,
      ~staggerLines: int=?,
      ~x: int=?,
      ~y: int=?,
      unit
    ) =>
    t =
    "";
};

module Axis = {
  type t;

  /** Creates an Axis.t value */
  [@bs.obj]
  external make:
    (
      ~_type: [@bs.string] [ | `linear | `logarithmic | `datetime | `category]=?,
      ~allowDecimals: bool=?,
      ~endOnTick: bool=?,
      ~gridLineWidth: int=?,
      ~labels: AxisLabel.t=?,
      ~lineColor: string=?,
      ~min: float=?,
      ~max: float=?,
      ~minPadding: int=?,
      ~maxPadding: int=?,
      ~offset: int=?,
      ~opposite: bool=?,
      ~reversed: bool=?,
      ~showLastLabel: bool=?,
      ~startOnTick: bool=?,
      ~tickColor: string=?,
      ~tickLength: int=?,
      ~tickPositions: array(int)=?,
      ~tickWidth: int=?,
      ~title: Title.t=?,
      unit
    ) =>
    t =
    "";
};

module ColorAxis = {
  type t;

  /** Creates a ColorAxis.t value */
  [@bs.obj]
  external make:
    (
      ~endOnTick: bool=?,
      ~labels: AxisLabel.t=?,
      ~max: int=?,
      ~min: int=?,
      ~reversed: bool=?,
      ~startOnTick: bool=?,
      ~stops: array((float, string))=?,
      ~tickAmount: int=?,
      unit
    ) =>
    t =
    "";
};

module Credits = {
  type t;

  /** Creates a Credits.t value */
  [@bs.obj]
  external make: (~enabled: bool=?, unit) => t = "";
};

module Exporting = {
  type t;

  /** Creates an Exporting.t value */
  [@bs.obj]
  external make: (~enabled: bool=?, unit) => t = "";
};

module Legend = {
  type t;
  type title;

  /** Creates a Legend.title value */
  [@bs.obj]
  external title: (~style: CssObject.t=?, ~text: string=?, unit) => title = "";

  /** Creates a Legend.t value */
  [@bs.obj]
  external make:
    (
      ~align: [@bs.string] [ | `left | `center | `right]=?,
      ~enabled: bool=?,
      ~itemStyle: CssObject.t=?,
      ~layout: [@bs.string] [ | `horizontal | `vertical | `proximate]=?,
      ~symbolHeight: int=?,
      ~symbolWidth: int=?,
      ~title: title=?,
      ~verticalAlign: [@bs.string] [ | `top | `middle | `bottom]=?,
      ~x: int=?,
      ~y: int=?,
      unit
    ) =>
    t =
    "";
};

[@bs.deriving {abstract: light}]
type make = {
  [@bs.optional]
  boost: Boost.t,
  [@bs.optional]
  chart: Chart.t,
  [@bs.optional]
  colorAxis: ColorAxis.t,
  [@bs.optional]
  credits: Credits.t,
  [@bs.optional]
  data: Data.t,
  [@bs.optional]
  exporting: Exporting.t,
  [@bs.optional]
  legend: Legend.t,
  [@bs.optional]
  series: array(Series.t),
  [@bs.optional]
  subtitle: Title.t,
  [@bs.optional]
  title: Title.t,
  [@bs.optional]
  tooltip: Tooltip.t,
  [@bs.optional]
  xAxis: Axis.t,
  [@bs.optional]
  yAxis: Axis.t,
};
