const path = require("path");
const { BundleAnalyzerPlugin } = require("webpack-bundle-analyzer");

module.exports = {
  entry: "./src/index.js",
  mode: "production",
  output: {
    filename: "bundle.js",
    path: path.resolve(__dirname, "dist"),
    libraryTarget: "umd"
  },
  externals: {
    react: "react",
    "mapbox-gl": "mapbox-gl"
  },
  plugins: [
    new BundleAnalyzerPlugin({
      analyzerMode: "static",
      openAnalyzer: false
    })
  ]
};
