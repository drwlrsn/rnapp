open ReactNative;
open ExNavigation;

[@react.component]
let make = () =>
  <Text> {"Hello world!"->React.string} </Text>;

make->setNavigationOptions(ReactNavigation.NavigationOptions.t(~title="Screen 1", ~headerTintColor="red", ()))