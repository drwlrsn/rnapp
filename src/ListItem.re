open ReactNative;

let styles =
  Style.(
    StyleSheet.create({
      "listItem":
        style(
          ~width=100.->pct,
          ~padding=10.->dp,
          ~backgroundColor="#eee",
          ~margin=5.->dp,
          ~flexDirection=`row,
          ~alignItems=`center,
          (),
        ),
      "placeImage": style(
        ~marginRight=8.->dp,
        ~height=30.->dp,
        ~width=30.->dp,
        ~resizeMode=`cover,
        ()
      )
    })
  );

[@react.component]
let make = (~place, ~onPressed) =>
  <TouchableOpacity onPress=onPressed>
    <View style=styles##listItem>
      <Image style=styles##placeImage source=Image.Source.fromRequired(Packager.require("./assets/saskatoon.jpg")) />
      <Text> place->Types.nameGet->React.string </Text>
    </View>
  </TouchableOpacity>;