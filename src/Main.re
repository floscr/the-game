let main = () => {
  /* Random.init(int_of_float(Js.Date.now())); /\* Initialize random seed based on date *\/ */
  Random.init(3); /* Initialize random seed based on date */
  Game.Loop.start();
};

main();
