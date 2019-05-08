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
  external make: (~margin: (int, int, int, int)=?, unit) => t = "";
};

module Boost = {
  type t;
  /** Creates a Boost.t value */
  [@bs.obj]
  external make: (~useGPUTranslations: bool=?, unit) => t = "";
};

module Tooltip = {
  type t;
  /** Creates a Tooltip.t value */
  [@bs.obj]
  external make: (~headerFormat: string=?, ~pointFormat: string=?, unit) => t =
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
      ~nullColor: string=?,
      ~tooltip: Tooltip.t=?,
      ~turboThreshold: float=?,
      unit
    ) =>
    t =
    "";
};

module Title = {
  type t;
  [@bs.obj]
  external make:
    (
      ~align: [@bs.string] [ | `left | `center | `right]=?,
      ~text: string=?,
      ~x: int=?,
      ~y: int=?,
      unit
    ) =>
    t =
    "";
};

module AxisLabel = {
  type t;
  /** Creates an axis AxisLabel.t value */
  [@bs.obj]
  external make:
    (
      ~align: [@bs.string] [ | `left | `center | `right]=?,
      ~x: int=?,
      ~y: int=?,
      ~format: string=?,
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
      ~title: Title.t=?,
      ~labels: AxisLabel.t=?,
      ~min: float=?,
      ~max: float=?,
      ~minPadding: int=?,
      ~maxPadding: int=?,
      ~startOnTick: bool=?,
      ~endOnTick: bool=?,
      ~tickPositions: array(int)=?,
      ~tickWidth: int=?,
      ~tickLength: int=?,
      ~showLastLabel: bool=?,
      ~min: int=?,
      ~max: int=?,
      ~reversed: bool=?,
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
      ~stops: array((float, string))=?,
      ~min: int=?,
      ~max: int=?,
      ~startOnTick: bool=?,
      ~endOnTick: bool=?,
      ~labels: AxisLabel.t=?,
      unit
    ) =>
    t =
    "";
};

module Credits = {
  type t;

    /** Creates a Credits.t value */
  [@bs.obj]
  external make:
    (
      ~enabled: bool=?,
      unit
    ) =>
    t =
    "";

}

[@bs.deriving {abstract: light}]
type make = {
  [@bs.optional]
  data: Data.t,
  [@bs.optional]
  boost: Boost.t,
  [@bs.optional]
  chart: Chart.t,
  [@bs.optional]
  series: array(Series.t),
  [@bs.optional]
  subtitle: Title.t,
  [@bs.optional]
  title: Title.t,
  [@bs.optional]
  xAxis: Axis.t,
  [@bs.optional]
  yAxis: Axis.t,
  [@bs.optional]
  colorAxis: ColorAxis.t,
  [@bs.optional]
  credits: Credits.t,
};
