let component = ReasonReact.statelessComponent("MapGL");

let make = (~message, _children) => {
  ...component,
  render: _ => <div> {ReasonReact.string(message)} </div>,
};

[@bs.deriving abstract]
type props = {message: string};

let default =
  ReasonReact.wrapReasonForJs(~component, props =>
    make(~message=props->messageGet, [||])
  );