type card =
  | RegularCard(int)
  | FireCard(int);

type cards = list(card);

type stack =
  | Upwards(cards)
  | Downwards(cards);

type playerId = int;

type player = {
  id: playerId,
  name: string,
  hand: cards,
};

type gameState = {
  players: list(player),
  deck: cards,
  stacks: (stack, stack, stack, stack),
  turn: playerId,
};

type gameAction =
  | Ok(gameState)
  | Error(string)
  | GameEnd(gameState);
