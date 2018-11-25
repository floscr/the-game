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
  deck: initDeck(),
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

let tapHand = tap(x => Js.log(List.nth(x.players, 0).hand |> Array.of_list));

let main = () => {
  /* Initialize random seed based on date */
  Random.init(int_of_float(Js.Date.now()));
  init() |> drawCards(7, 0) |> drawCards(7, 1) |> tapHand(0) |> tapHand(1);
};

main();
