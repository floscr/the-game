let showCard = card =>
  switch (card) {
  | Cards.RegularCard(x) => string_of_int(x)
  | _ => ""
  };

let showStack = card =>
  switch (card) {
  | Cards.Upwards([x, ..._xs]) => "Up " ++ showCard(x)
  | Cards.Upwards([]) => "Up 0"
  | Cards.Downwards([x, ..._xs]) => "Down " ++ showCard(x)
  | Cards.Downwards([]) => "Down 0"
  };
