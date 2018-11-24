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

let draw = (amount: int, id: int, state: game_state): game_state => {
  let {players, deck, stacks} = state;
  let (drawnCards, newDeck) = draw(amount, deck);
  state;
  {
    ...state,
    deck: newDeck,
    players:
      mapMatching(x => x.id === id, gainCards(drawnCards), players, []),
  };
};

let tapHand = tap(x => Js.log(List.nth(x.players, 0).hand |> Array.of_list));

init() |> tapHand |> draw(3, 0) |> tapHand |> draw(5, 0) |> tapHand;
