open ReactNavigation;

include ReactNavigation.Make({
  type screenProps = {. "someProp": int};
});