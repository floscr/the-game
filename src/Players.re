open Cards;

type player = {
  id: int,
  name: string,
  hand: cards,
};

let player_names = [|
  "Johanna",
  "Flo",
  "Theresa",
  "Pia",
  "Augustin",
  "Andreas",
|];

let handLens = Rationale.Lens.make(x => x.hand, (v, a) => {...a, hand: v});

let gainCards = (cards, player): player => {
  ...player,
  hand: List.append(player.hand, cards),
};
