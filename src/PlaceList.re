open ReactNative;

let styles =
  Style.(StyleSheet.create({"listContainer": style(~width=100.->pct, ())}));

[@bs.deriving abstract]
type place = {
  id: int,
  p: string
};

[@react.component]
let make = (~places, ~onDelete) =>
  <FlatList
    style=styles##listContainer
    data={List.mapi((idx, p) => place(~id=idx, ~p=p), places)->Array.of_list}
    keyExtractor={(place, _idx) => place->idGet->string_of_int}
    renderItem={place =>
      <ListItem
        key={place##index->string_of_int}
        placeName=place##item->pGet
        onPressed={_ => onDelete(place##item->idGet)}
      />}
  />;