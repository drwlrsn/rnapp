open ReactNavigation;
open ExNavigation;

let routes = {
  "Screen1": Screen1.make,
};

let navigator = StackNavigator.make(routes);