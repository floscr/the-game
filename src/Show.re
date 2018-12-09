open Rationale;
open Types;

let showPlayer = player => {
  let {id, name, hand} = player;
  let prettyHand = List.map(UI.showCard, hand) |> RList.join(" | ");
  {j|$name (Player $id)
$prettyHand
|j};
};

let showStacks = stacks => {
  let heads = Utils.map4Tuple(UI.showStack, stacks);
  {j|Fields: $heads
|j};
};

let tapGame =
  Utils.tap(state => {
    Js.log(showStacks(state.stacks));
    Js.log(
      List.map(p => showPlayer(p), state.players) |> RList.join("\n"),
    );
  });
