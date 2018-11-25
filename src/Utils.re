/* From https://stackoverflow.com/a/15095713 */
let shuffle = xs => {
  let with_random = List.map(x => (Random.bits(), x), xs);
  let sorted = List.sort(compare, with_random);
  List.map(snd, sorted);
};

/* Maps the item matching predicate in a list */
let rec mapMatching = (pred: 'a => bool, fn: 'a => 'b, xs: list('a), acc) =>
  switch (xs) {
  | [] => acc
  | [a, ...b] =>
    switch (pred(a)) {
    | true => List.flatten([acc, [fn(a)], b])
    | _ => mapMatching(pred, fn, b, List.append(acc, [a]))
    }
  };

let tap = (fn, x) => {
  fn(x);
  x;
};

let map4Tuple = (f, (a, b, c, d)) => (f(a), f(b), f(c), f(d));

let join4Tuple = (a, b, c, d) => a ++ " " ++ b ++ " " ++ c ++ " " ++ d;
