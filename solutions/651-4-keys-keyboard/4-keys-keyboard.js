const maxA = (n) =>
  n < 7 
    ? n 
    : Math.max(
      3 * maxA(n - 4),
      4 * maxA(n - 5),
    )