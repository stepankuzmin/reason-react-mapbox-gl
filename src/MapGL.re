open Belt;

type state = {
  map: ref(option(MapboxGL.Map.t)),
  containerRef: ref(option(Dom.element)),
};

let setContainerRef = (theRef, {ReasonReact.state}) =>
  state.containerRef := Js.Nullable.toOption(theRef);

let component = ReasonReact.reducerComponentWithRetainedProps("MapGL");

let make = (~className, ~accessToken, ~style, ~center, ~zoom, _children) => {
  ...component,
  // retainedProps: {
  //   zoom: zoom,
  // },
  initialState: () => {map: ref(None), containerRef: ref(None)},
  didMount: self => {
    let containerRef = self.state.containerRef^;
    if (Option.isSome(containerRef)) {
      MapboxGL.setAccessToken(MapboxGL.mapboxGl, accessToken);

      let map_options = {
        "container": Option.getExn(containerRef),
        "style": style,
        "center": center,
        "zoom": zoom,
      };

      let map = MapboxGL.create_map(map_options);
      self.state.map := Some(map);
    };
  },
  didUpdate: ({oldSelf, newSelf}) => {
    let map = Option.getExn(newSelf.state.map^);
    let zoom = MapboxGL.Map.getZoom(map);
    // if (oldSelf.retainedProps.zoom === zoom) {
    //   MapboxGL.Map.setZoom(map, zoom);
    // };
    ();
  },
  reducer: ((), _state) => ReasonReact.NoUpdate,
  render: self => <div className ref={self.handle(setContainerRef)} />,
};

[@bs.deriving abstract]
type props = {
  className: string,
  accessToken: string,
  style: string,
  center: (int, int),
  zoom: int,
};

let default =
  ReasonReact.wrapReasonForJs(~component, props =>
    make(
      ~className=props->classNameGet,
      ~accessToken=props->accessTokenGet,
      ~style=props->styleGet,
      ~center=props->centerGet,
      ~zoom=props->zoomGet,
      [||],
    )
  );