open ReactNative;
open ExNavigation;

module AppContainer = (val makeAppContainer(MyStackNavigator.navigator));
let screenProps = {"someProp": 42};

[@react.component]
let make = () => <AppContainer screenProps />;