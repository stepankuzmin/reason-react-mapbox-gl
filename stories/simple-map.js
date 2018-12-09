import React from "react";
import "mapbox-gl/dist/mapbox-gl.css";

import MapGL from "../src/MapGL.bs";
import "./styles.css";

const accessToken = process.env.STORYBOOK_MAPBOX_ACCESS_TOKEN;

export default () => <MapGL className="map" accessToken={accessToken} />;
