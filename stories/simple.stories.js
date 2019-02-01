import React from 'react';
import 'mapbox-gl/dist/mapbox-gl.css';

import MapGL from '../src/MapGL.re';
import './styles.css';

const accessToken = process.env.STORYBOOK_MAPBOX_ACCESS_TOKEN;

const SimpleMap = () => <MapGL className="map" accessToken={accessToken} />;

export default SimpleMap;
