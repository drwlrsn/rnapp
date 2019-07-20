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
          (),
        ),
    })
  );

[@react.component]
let make = (~placeName, ~onPressed) =>
  <TouchableOpacity onPress=onPressed>
    <View style=styles##listItem>
      <Text> placeName->React.string </Text>
    </View>
  </TouchableOpacity>;