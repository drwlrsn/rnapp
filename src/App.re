/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * Converted from https://github.com/facebook/react-native/blob/d752446b23e0a12171ca0c01d20f5be625f40455/template/App.js
 */
open ReactNative;

/*
 Here is StyleSheet that is using Style module to define styles for your components
 The main different with JavaScript components you may encounter in React Native
 is the fact that they **must** be defined before being referenced
 (so before actual component definitions)
 More at https://reasonml-community.github.io/reason-react-native/en/docs/apis/Style/
 */
let styles =
  Style.(
    StyleSheet.create({
      "container":
        style(
          ~flex=1.,
          ~justifyContent=`flexStart,
          ~alignItems=`center,
          ~backgroundColor="#F5FCFF",
          ~padding=30.->dp,
          (),
        ),
      "inputContainer":
        style(
          ~width=100.->pct,
          ~flexDirection=`row,
          ~justifyContent=`spaceBetween,
          ~alignItems=`center,
          (),
        ),
      "input": style(~width=70.->pct, ()),
      "placeButton": style(~width=30.->pct, ()),
      "listContainer": style(~width=100.->pct, ()),
    })
  );


[@react.component]
let app = () => {
  let (placesState, setPlacesState) = React.useState(() => []);
  let handleOnAdd = (place: string) =>
    setPlacesState(_ => [place, ...placesState]);
  let handleOneDelete = idx => setPlacesState(state => Util.remove_at(idx, state));
  <View style=styles##container>
    <PlaceInput onAdd=handleOnAdd />
    <PlaceList
      places=placesState
      onDelete=handleOneDelete
    />
  </View>;
};