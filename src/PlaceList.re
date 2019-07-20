open ReactNative;

let styles =
  Style.(StyleSheet.create({"listContainer": style(~width=100.->pct, ())}));

[@react.component]
let make = (~places, ~onDelete) =>
  <View style=styles##listContainer>
    {List.mapi(
       (idx, p) =>
         <ListItem
           key={idx->string_of_int}
           placeName=p
           onPressed={_ => onDelete(idx)}
         />,
       places,
     )
     ->Array.of_list
     ->React.array}
  </View>;