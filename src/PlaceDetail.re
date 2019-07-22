open ReactNative;
open Types;

let styles =
  Style.(
    StyleSheet.create({
      "modalContainer": style(~margin=22.->dp, ()),
      "placeImage": style(~width=100.->pct, ~height=200.->dp, ()),
      "placeName": style(~fontSize=30., ~textAlign=`center, ())
    })
  );

[@react.component]
let make = (~selectedPlace, ~onDelete, ~onClose) => {
  let modalContent =
    switch (selectedPlace) {
    | None => React.null
    | Some((idx: int, place: place)) =>
      <View style=styles##modalContainer>
        <Image style=styles##placeImage source={place->imageGet} />
        <Text style=styles##placeName> {place->nameGet->React.string} </Text>
        <View>
          <Button
            title="Delete Place"
            onPress={_ => onDelete(idx)}
            color=Color.red
          />
          <Button title="Cancel" onPress={onClose} />
        </View>
      </View>
    };
  <Modal
    visible={
      switch (selectedPlace) {
      | None => false
      | Some(_) => true
      }
    }
    animationType=`slide>
    modalContent
  </Modal>;
};