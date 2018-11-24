open Rationale;
open Rationale.RList;

type card =
  | RegularCard(int)
  | FireCard(int);

type cards = list(card);

type stack =
  | Upwards(cards)
  | Downwards(cards);

let duplicate = List.fold_left((acc, x) => [x, x, ...acc], []);

let draw = splitAt;

let initDeck = () =>
  rangeInt(1, 1, 99) |> List.map(x => RegularCard(x)) |> duplicate;
