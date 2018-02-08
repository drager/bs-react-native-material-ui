# BuckleScript bindings for [React Native Material Ui](https://github.com/xotahal/react-native-material-ui)

## Status

Not all components got bindings yet, but all should be covered very soon. Check out the
source.

Feel free to create an issue or pull request if you find anything missing.

## Installation

`yarn add bs-react-native-material-ui`
`yarn add react-native-material-ui`

Then add `react-native-material-ui` to `bs-dependencies` in your `bsconfig.json`:

```json
{
  "bs-dependencies": ["react-native-material-ui"]
}
```

## Usage

```reason
let uiTheme: ReactNativeMaterialUi.ThemeProvider.uiTheme = {
  palette: {
    primaryColor: "#000000"
  }
};

let app = () =>
  <ReactNativeMaterialUi.ThemeProvider uiTheme>
    <View>
      <ReactNativeMaterialUi.ActionButton
          actions=(
            ReactNativeMaterialUi.ActionButton.ShapeAction({
              icon: "done",
              name: "Done",
              label: "Yello"
            })
          )
        />
        
    </View>
  </ReactNativeMaterialUi.ThemeProvider>;
```

## Bindings

