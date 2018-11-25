open Rationale;
open Players;
open Cards;
open Utils;

type game_state = {
  players: list(player),
  deck: cards,
  stacks: (stack, stack, stack, stack),
};

let init = (): game_state => {
  players: [
    {id: 0, name: player_names[0], hand: []},
    {id: 1, name: player_names[1], hand: []},
  ],
  deck: initDeck() |> Utils.shuffle,
  stacks: (Upwards([]), Upwards([]), Downwards([]), Downwards([])),
};

let drawCards = (amount: int, id: int, state: game_state): game_state => {
  let {players, deck} = state;
  let (drawnCards, newDeck) = Cards.draw(amount, deck);
  {
    ...state,
    deck: newDeck,
    players:
      mapMatching(
        x => x.id === id,
        Players.gainCards(drawnCards),
        players,
        [],
      ),
  };
};

let showPlayer = player => {
  let {id, name, hand} = player;
  let prettyHand = List.map(UI.showCard, hand) |> RList.join(" | ");
  {j|$name (Player $id)
$prettyHand
|j};
};

let tapGame =
  tap(state =>
    Js.log(List.map(p => showPlayer(p), state.players) |> RList.join("\n"))
  );

let main = () => {
  Random.init(int_of_float(Js.Date.now())); /* Initialize random seed based on date */
  init() |> drawCards(7, 0) |> drawCards(7, 1) |> tapGame;
};

main();
