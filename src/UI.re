let showCard = card =>
  switch (card) {
  | Cards.RegularCard(x) => string_of_int(x)
  | _ => ""
  };
