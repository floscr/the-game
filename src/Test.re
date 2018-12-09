open Rationale;
open Rationale.Option.Infix;
open Rationale.Lens;

type basic = {
  id: int,
  name: string,
};

type stateType =
  | Basic(basic)
  | Error(string);

let ids = [{id: 1, name: "john"}, {id: 2, name: "karl"}];

let idLens = Lens.make(a => a.id, (v, a) => {...a, id: v});
let nameLens = Lens.make(a => a.name, (v, a) => {...a, name: v});

let found = ids =>
  RList.find(x => x.id === 1, ids) <$> over(idLens, x => x + 1);

let updateIds = (ids, id) =>
  Some(ids)
  >>= RList.find(x => x.id === id)
  <$> over(idLens, x => x + 1)
  <$> over(nameLens, String.uppercase)
  >>= (x => Some(Basic(x)))
  |> Option.default(Error("No such user"));

/* let found = over(idLens >>- Lens.optional(4), x => x + 1, id); */

Js.log(
  switch (updateIds(ids, 2)) {
  | Basic(x) => x.name ++ ": " ++ string_of_int(x.id)
  | Error(x) => "Error: " ++ x
  },
);
