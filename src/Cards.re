open Types;
open Rationale;

module Deck = {
  let duplicate = List.fold_left((acc, x) => [x, x, ...acc], []);

  let draw = RList.splitAt;

  let init = () =>
    RList.rangeInt(1, 1, 99) |> List.map(x => RegularCard(x)) |> duplicate;
};
