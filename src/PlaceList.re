open ReactNative;

let styles =
  Style.(StyleSheet.create({"listContainer": style(~width=100.->pct, ())}));

[@bs.deriving abstract]
type placeData = {
  id: int,
  p: Types.place
};

[@react.component]
let make = (~places, ~onSelect) =>
  <FlatList
    style=styles##listContainer
    data={List.mapi((idx, p) => placeData(~id=idx, ~p=p), places)->Array.of_list}
    keyExtractor={(place, _idx) => place->idGet->string_of_int}
    renderItem={place =>
      <ListItem
        key={place##index->string_of_int}
        place=place##item->pGet
        onPressed={_ => onSelect(place##item->idGet, place##item->pGet)}
      />}
  />;