open Types;

let handLens = Rationale.Lens.make(x => x.hand, (v, a) => {...a, hand: v});

let gainCards = (cards, player): player => {
  ...player,
  hand: List.append(player.hand, cards),
};
