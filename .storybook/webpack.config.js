const path = require('path');

module.exports = (storybookBaseConfig, configType) => {
  storybookBaseConfig.module.rules.push({
    test: /\.css$/,
    loaders: ['style-loader', 'css-loader'],
    include: path.resolve(__dirname, '../')
  });

  storybookBaseConfig.module.rules.push({
    test: /\.(re|rei|ml|mli)$/,
    use: [
      {
        loader: require.resolve('bs-loader')
      }
    ]
  });

  storybookBaseConfig.resolve.extensions.push('.re', '.ml');

  return storybookBaseConfig;
};
