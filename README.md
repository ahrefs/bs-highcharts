# bs-highcharts

These are [Bucklescript](https://bucklescript.github.io/) bindings for [highcharts](https://www.highcharts.com/).
🚧 They are not complete. Types can change in a backwards incompatible way between minor versions. 🚧

# Install

```
yarn add @ahrefs/bs-highcharts
```

# Setup

Add `bs-highcharts` to `bs-dependencies` in your `bsconfig.json`.

```js
{
  /* ... */
  "bs-dependencies": [
    "@ahrefs/bs-highcharts"
  ],
  /* ... */
}
```

# Usage Example

```reason
open Highcharts;

let options =
  Options.(
    make(
      ~title=Title.make(~text="My chart", ()),
      ~series=[|Series.line(~data=[|1, 2, 3|], ())|],
      (),
    )
  );

Highcharts.chart("container", options);
```

Check [Highcharts API documentation](https://api.highcharts.com/highcharts/) for available props in the original JavaScript library. Several options might not be available in these bindings, PRs welcome! 
