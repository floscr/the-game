type card =
  | RegularCard(int)
  | FireCard(int);

type cards = list(card);

type stack =
  | Upwards(cards)
  | Downwards(cards);

type player = {
  id: int,
  name: string,
  hand: cards,
};

type game_state = {
  players: list(player),
  deck: cards,
  stacks: (stack, stack, stack, stack),
};
