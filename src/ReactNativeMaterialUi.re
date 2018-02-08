[@bs.module "react-native-material-ui"]
external color : ReasonReact.reactClass = "COLOR";

module ThemeProvider = {
  [@bs.module "react-native-material-ui"]
  external themeProvider : ReasonReact.reactClass = "ThemeProvider";
  type palette = {primaryColor: string};
  type uiTheme = {palette};
  let make = (~uiTheme: uiTheme, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=themeProvider,
      ~props={
        "uiTheme": {
          "palette": {
            "primaryColor": uiTheme.palette.primaryColor
          }
        }
      },
      children
    );
};

module ActionButton = {
  [@bs.module "react-native-material-ui"]
  external actionButton : ReasonReact.reactClass = "ActionButton";
  type shape = {
    icon: string,
    label: string,
    name: string
  };
  type actions =
    | StringAction(string)
    | ElementAction(ReasonReact.reactElement)
    | ShapeAction(shape);
  type transition =
    | Toolbar
    | SpeedDial;
  type style = {
    container: option(BsReactNative.Style.t),
    icon: option(BsReactNative.Style.t)
  };
  let make =
      (
        ~actions: option(actions)=?,
        ~onPress: option(unit => unit)=?,
        ~onLongPress: option(unit => unit)=?,
        ~hidden: option(bool)=?,
        ~icon: option(string)=?,
        ~transition: option(transition)=?,
        ~style: option(style)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=actionButton,
      ~props=
        Js.Undefined.(
          {
            "actions": from_opt(actions),
            "onPress": from_opt(onPress),
            "onLongPress": from_opt(onLongPress),
            "hidden":
              switch hidden {
              | Some(true) => Js.true_
              | Some(false) => Js.false_
              | None => Js.false_
              },
            "icon": from_opt(icon),
            "transition":
              from_opt(
                switch transition {
                | Some(transition) =>
                  switch transition {
                  | Toolbar => Some("toolbar")
                  | SpeedDial => Some("speedDial")
                  }
                | None => None
                }
              ),
            "style": from_opt(style)
          }
        ),
      children
    );
};

module ListItem = {
  [@bs.module "react-native-material-ui"]
  external listItem : ReasonReact.reactClass = "ListItem";
  type palette = {primaryColor: string};
  type uiTheme = {palette};
  type centerElement = {
    primaryText: string,
    secondaryText: option(string),
    tertiaryText: option(string)
  };
  let centerElement = (~secondaryText=?, ~tertiaryText=?, primaryText) => {
    primaryText,
    secondaryText,
    tertiaryText
  };
  let make =
      (
        ~divider: option(bool)=?,
        ~onPress: option(unit => unit)=?,
        ~centerElement: option(centerElement)=?,
        ~leftElement: option(ReasonReact.reactElement)=?,
        ~rightElement: option(ReasonReact.reactElement)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=listItem,
      ~props=
        Js.Undefined.(
          {
            "divider":
              switch divider {
              | Some(true) => Js.true_
              | Some(false) => Js.false_
              | None => Js.false_
              },
            "onPress": from_opt(onPress),
            "centerElement":
              from_opt(
                switch centerElement {
                | Some(centerElement) =>
                  let dict = Js.Dict.empty();
                  Js.Dict.set(dict, "primaryText", centerElement.primaryText);
                  switch centerElement.secondaryText {
                  | Some(secondaryText) =>
                    Js.Dict.set(dict, "secondaryText", secondaryText)
                  | None => ()
                  };
                  Some(dict);
                | None => None
                }
              ),
            "leftElement": from_opt(leftElement),
            "rightElement": from_opt(rightElement)
          }
        ),
      children
    );
};

module Subheader = {
  [@bs.module "react-native-material-ui"]
  external subheader : ReasonReact.reactClass = "Subheader";
  let make =
      (~text: string, ~inset: option(bool)=?, ~lines: option(int)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=subheader,
      ~props=
        Js.Undefined.(
          {
            "text": text,
            "inset":
              switch inset {
              | Some(true) => Js.true_
              | Some(false) => Js.false_
              | None => Js.false_
              },
            "lines": from_opt(lines)
          }
        ),
      children
    );
};

module IconToggle = {
  [@bs.module "react-native-material-ui"]
  external iconToggle : ReasonReact.reactClass = "IconToggle";
  let make =
      (
        ~color: option(string)=?,
        ~underlayColor: option(string)=?,
        ~maxOpacity: option(int)=?,
        ~percent: option(int)=?,
        ~disabled: option(bool)=?,
        ~size: option(int)=?,
        ~name: string,
        ~onPress: option(unit => unit)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=iconToggle,
      ~props=
        Js.Undefined.(
          {
            "color": from_opt(color),
            "maxOpacity": from_opt(maxOpacity),
            "percent": from_opt(percent),
            "underlayColor": from_opt(underlayColor),
            "disabled":
              switch disabled {
              | Some(true) => Js.true_
              | Some(false) => Js.false_
              | None => Js.false_
              },
            "size": from_opt(size),
            "name": name,
            "onPress": from_opt(onPress)
          }
        ),
      children
    );
};

let optionBoolToJsBool = option =>
  switch option {
  | Some(true) => Js.true_
  | Some(false) => Js.false_
  | None => Js.false_
  };

module Button = {
  [@bs.module "react-native-material-ui"]
  external button : ReasonReact.reactClass = "Button";
  let make =
      (
        ~disabled: option(bool)=?,
        ~raised: option(bool)=?,
        ~primary: option(bool)=?,
        ~accent: option(bool)=?,
        ~onPress: option(unit => unit)=?,
        ~onLongPress: option(unit => unit)=?,
        ~text: string,
        ~upperCase: option(bool)=?,
        ~icon: option(string)=?,
        ~style: option(BsReactNative.Style.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=button,
      ~props=
        Js.Undefined.(
          {
            "disabled": optionBoolToJsBool(disabled),
            "raised": optionBoolToJsBool(raised),
            "primary": optionBoolToJsBool(primary),
            "accent": optionBoolToJsBool(accent),
            "onPress": from_opt(onPress),
            "onLongPress": from_opt(onLongPress),
            "text": text,
            "upperCase": from_opt(upperCase),
            "icon": from_opt(icon),
            "style": from_opt(style)
          }
        ),
      children
    );
};