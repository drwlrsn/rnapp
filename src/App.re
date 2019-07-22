open ReactNative;
open Types;

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
  let (selectedPlace, setSelectedPlace) = React.useState(() => None);
  let handleOnAdd = (p: string) =>
    setPlacesState(_ =>
      [
        place(
          ~key=Random.int(1000000),
          ~name=p,
          ~image=
            Image.Source.fromRequired(
              Packager.require("./assets/saskatoon.jpg"),
            ),
        ),
        ...placesState,
      ]
    );
  let handleOnSelectPlace = (idx, place) =>
    setSelectedPlace(_ => Some((idx, place)));
  let handleOnClose = _ => setSelectedPlace(_ => None);
  let handleOneDelete = idx => {
    setPlacesState(state => Util.remove_at(idx, state));
    handleOnClose();
  };

  <View style=styles##container>
    <PlaceDetail selectedPlace onDelete=handleOneDelete onClose=handleOnClose />
    <PlaceInput onAdd=handleOnAdd />
    <PlaceList places=placesState onSelect=handleOnSelectPlace />
  </View>;
};