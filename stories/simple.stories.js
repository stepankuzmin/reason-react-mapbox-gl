import React from 'react';
import { text, boolean, number } from '@storybook/addon-knobs';
import 'mapbox-gl/dist/mapbox-gl.css';

import MapGL from '../src/MapGL.re';
import './styles.css';

const accessToken = process.env.STORYBOOK_MAPBOX_ACCESS_TOKEN;

const SimpleMap = () => {
  const style = text('style', 'mapbox://styles/mapbox/streets-v9');
  const zoom = number('zoom', 0);

  console.log({ style, zoom });

  return (
    <MapGL
      className="map"
      accessToken={accessToken}
      style={style}
      center={[0, 0]}
      zoom={zoom}
    />
  );
};

export default SimpleMap;
