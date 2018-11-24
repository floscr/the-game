/* From https://stackoverflow.com/a/15095713 */
let shuffle = xs => {
  let with_random = List.map(x => (Random.bits(), x), xs);
  let sorted = List.sort(compare, with_random);
  List.map(snd, sorted);
};

/* Maps the item matching predicate in a list */
/* TODO: Stop iterating when predicate is found, otherwise can just use filter_ */
let rec mapMatching = (pred: 'a => bool, fn: 'a => 'b, xs: list('a), acc) =>
  switch (xs) {
  | [] => acc
  | [a, ...b] =>
    let current = pred(a) ? fn(a) : a;
    mapMatching(pred, fn, b, List.append(acc, [current]));
  };

Js.log(
  mapMatching(x => x == 1, x => x + 10, [3, 2, 1], []) |> Array.of_list,
);

let tap = (fn, x) => {
  fn(x);
  x;
};
