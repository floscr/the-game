open Cards;
open Types;

let names = [|"Johanna", "Flo", "Theresa", "Pia", "Augustin", "Andreas"|];

let init = () => {
  players: [
    {id: 0, name: names[0], hand: []},
    {id: 1, name: names[1], hand: []},
  ],
  deck: Deck.init() |> Utils.shuffle,
  stacks: (Upwards([]), Upwards([]), Downwards([]), Downwards([])),
  turn: 0,
};

let drawCards = (amount: int, id: int, state: game_state) => {
  let {players, deck} = state;
  let (drawnCards, newDeck) = Deck.draw(amount, deck);
  {
    ...state,
    deck: newDeck,
    players:
      Utils.mapMatching(
        x => x.id === id,
        Players.gainCards(drawnCards),
        players,
        [],
      ),
  };
};

module Loop = {
  let start = () =>
    init() |> drawCards(7, 0) |> drawCards(7, 1) |> Show.tapGame;
};
