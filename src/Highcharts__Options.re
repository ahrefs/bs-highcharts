type t;
[@bs.module] external default: t = "highcharts";

module Series = {
  type t;
  /** Creates a `line` series */
  [@bs.obj]
  external line: (~_type: [@bs.as "line"] _, ~data: array(int), unit) => t =
    "";
};

module Title = {
  [@bs.deriving {abstract: light}]
  type make = {
    [@bs.optional]
    text: string,
  };
};

[@bs.deriving {abstract: light}]
type make = {
  [@bs.optional]
  series: array(Series.t),
  [@bs.optional]
  title: Title.make,
};
