/* From https://stackoverflow.com/a/15095713 */
let shuffle = xs => {
  let with_random = List.map(x => (Random.bits(), x), xs);
  let sorted = List.sort(compare, with_random);
  List.map(snd, sorted);
};
