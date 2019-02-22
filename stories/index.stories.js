import { storiesOf } from '@storybook/react';
import { withKnobs } from '@storybook/addon-knobs';

import SimpleMap from './simple.stories';

const stories = storiesOf('MapGL', module);
stories.addDecorator(withKnobs);

stories.add('Simple map', SimpleMap);
