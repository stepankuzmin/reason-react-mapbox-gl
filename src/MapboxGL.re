module Map = {
  type t;
};

type map_options = {
  .
  "container": Dom.element,
  "style": string,
  "center": (int, int),
  "zoom": int,
};

[@bs.module "mapbox-gl"] [@bs.new]
external create_map: map_options => Map.t = "Map";

[@bs.module "mapbox-gl"] external accessToken: ref(string) = "accessToken";