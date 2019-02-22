type mapboxGlModule;

module Map = {
  type t;

  [@bs.send] external getZoom: t => int = "";
  [@bs.send] external setZoom: (t, int) => t = "";
};

type map_options = {
  .
  "container": Dom.element,
  "style": string,
  "center": (int, int),
  "zoom": int,
};

[@bs.module] external mapboxGl: mapboxGlModule = "mapbox-gl";

[@bs.module "mapbox-gl"] [@bs.new]
external create_map: map_options => Map.t = "Map";

[@bs.set]
external setAccessToken: (mapboxGlModule, string) => unit = "accessToken";