open ReactNative;

let styles =
  Style.(
    StyleSheet.create({
      "inputContainer":
        style(
          ~width=100.->pct,
          ~flexDirection=`row,
          ~justifyContent=`spaceBetween,
          ~alignItems=`center,
          (),
        ),
      "input": style(~width=70.->pct, ()),
    })
  );

[@react.component]
let make = (~onAdd) => {
  let (inputState, setInputState) = React.useState(() => "");
  <View style=styles##inputContainer>
    <TextInput
      style=styles##input
      value=inputState
      onChangeText={text => setInputState(_ => text)}
      placeholder="Add a place"
    />
    <Button
      onPress={_ =>
        if (inputState->String.trim == "") {
          ();
        } else {
          onAdd(inputState);
          setInputState(_ => "");
        }
      }
      title="Add"
    />
  </View>;
};