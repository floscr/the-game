open Types;

let showCard = card =>
  switch (card) {
  | RegularCard(x) => string_of_int(x)
  | _ => ""
  };

let showStack = card =>
  switch (card) {
  | Upwards([x, ..._xs]) => "Up " ++ showCard(x)
  | Upwards([]) => "Up 0"
  | Downwards([x, ..._xs]) => "Down " ++ showCard(x)
  | Downwards([]) => "Down 0"
  };
