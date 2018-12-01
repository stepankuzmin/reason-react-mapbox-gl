open Belt;

type state = {
  map: ref(option(MapboxGL.Map.t)),
  containerRef: ref(option(Dom.element)),
};

let setContainerRef = (theRef, {ReasonReact.state}) =>
  state.containerRef := Js.Nullable.toOption(theRef);

let component = ReasonReact.reducerComponent("MapGL");

let make = (~className, ~accessToken, _children) => {
  ...component,
  initialState: () => {map: ref(None), containerRef: ref(None)},
  didMount: self => {
    let containerRef = self.state.containerRef^;
    if (Option.isSome(containerRef)) {
      MapboxGL.setAccessToken(MapboxGL.mapboxGl, accessToken);

      let map_options = {
        "container": Option.getExn(containerRef),
        "style": "mapbox://styles/mapbox/streets-v9",
        "center": (0, 0),
        "zoom": 0,
      };

      let map = MapboxGL.create_map(map_options);
      self.state.map := Some(map);
    };
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
      [||],
    )
  );