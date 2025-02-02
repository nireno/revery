open Revery;
open Revery.UI;
open Revery.UI.Components;

let containerStyle =
  Style.[
    position(`Absolute),
    top(0),
    bottom(0),
    left(0),
    right(0),
    alignItems(`Center),
    justifyContent(`Center),
    flexDirection(`Column),
    backgroundColor(Colors.white),
  ];

module Example = {
  type inputFields = {
    first: string,
    second: string,
  };

  let component = React.component("Example");

  let createElement = (~children as _, ()) =>
    component(hooks => {
      let ({first, second}, setValue, hooks) =
        Hooks.state({first: "", second: ""}, hooks);

      (
        hooks,
        <View style=containerStyle>
          <View
            style=Style.[
              flexDirection(`Row),
              alignItems(`Center),
              justifyContent(`Center),
            ]>
            <Input
              placeholder="Insert text here"
              onChange={({value, _}) => setValue({first: value, second})}
              onFocus={() => Console.log("Input example focused!")}
              onBlur={() => Console.log("Input example blurred!")}
              value=first
            />
            <Button
              height=50
              width=100
              fontSize=15
              title="Reset"
              onClick={() => setValue({first: "", second})}
            />
            <Button
              height=50
              width=100
              fontSize=15
              title="Set value"
              onClick={() => setValue({first: "New value", second})}
            />
          </View>
          <Padding padding=20>
            <BoxShadow
              boxShadow={Style.BoxShadow.make(
                ~xOffset=-5.,
                ~yOffset=2.,
                ~color=Colors.black,
                ~blurRadius=20.,
                ~spreadRadius=0.,
                (),
              )}>
              <Input
                placeholder="custom input"
                placeholderColor=Colors.plum
                cursorColor=Colors.white
                autofocus=true
                onChange={({value, _}) => setValue({first, second: value})}
                onKeyDown={event => Console.log(event)}
                style=Style.[
                  backgroundColor(Colors.paleVioletRed),
                  color(Colors.white),
                  height(50),
                ]
              />
            </BoxShadow>
          </Padding>
        </View>,
      );
    });
};

let render = () => <Example />;
