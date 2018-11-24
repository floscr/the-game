open Rationale.RList;

type card_type =
  | RegularCard
  | FireCard;

type card_value = int;

type card = (card_type, card_value);

type hand =
  | Rlist(card);

let initDeck = () => rangeInt(1, 1, 99);

Js.log(initDeck() |> last);
