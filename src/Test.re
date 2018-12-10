open Rationale;
open Rationale.Option.Infix;
open Rationale.Lens;

type basic = {
  id: int,
  name: string,
  partners: list(int),
};

type stateType =
  | Basic(basic)
  | Error(string);

let ids = [
  {id: 1, name: "john", partners: []},
  {id: 2, name: "karl", partners: [1]},
];

let idLens = Lens.make(a => a.id, (v, a) => {...a, id: v});
let nameLens = Lens.make(a => a.name, (v, a) => {...a, name: v});
let partnersLens = Lens.make(a => a.partners, (v, a) => {...a, partners: v});

let found = ids =>
  RList.find(x => x.id === 1, ids) <$> over(idLens, x => x + 1);

let updateIds = (ids, id) =>
  Some(ids)
  >>= RList.find(x => x.id === id)
  <$> over(idLens, x => x + 1)
  <$> over(nameLens, String.uppercase)
  >>= (x => Some(Basic(x)))
  |> Option.default(Error("No such user"));

let findPartnerId = (partnerId, userIds) = {
  switch(RList.find(u => u.id === partnerId, userIds)) {
    | Some(x) => x
    | None => None
  }
}

let getPartner = (ids, id) =>
  Some(ids)
  >>= RList.find(x => x.id === id)
  >>= over(partnersLens, (partners => {
    Rlist.find((switch (partnerId => RList.find(id => id === partnerId, ids))), partners)
}))

/* let found = over(idLens >>- Lens.optional(4), x => x + 1, id); */

Js.log(
  switch (updateIds(ids, 2)) {
  | Basic(x) => x.name ++ ": " ++ string_of_int(x.id)
  | Error(x) => "Error: " ++ x
  },
);
