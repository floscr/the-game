open Players;
open Cards;

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

/* let adjustPlayers = (players: list(players), id: int, fn: player => player) => */
/*   RList.findIndex(x => x.id === id, players) */
/*   >>= (id => RList.intersperse(id)); */

/* let draw = (state: game_state, amount: int, ~playerId as id: int): game_state => { */
/*   let {players, deck, stacks} = state; */
/*   let (drawnCards, newDeck) = draw(amount, deck); */
/*   let player = List.find(x => x.id === id, players); */
/*   (); */
/* }; */

/* let main = () => { */
/*   let deck = ref(initDeck()); */
/*   (); */
/* }; */

Js.log(initDeck() |> Utils.shuffle |> Array.of_list);
