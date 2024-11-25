function validArrangement(pairs: number[][]): number[][] {
  const edgeCount: Map<number, number> = new Map<number, number>();
  const graph: Map<number, number[]> = new Map<number, number[]>();
  let result: number[] = [];

  const search = (x: number) => {
    while (graph.has(x) && graph.get(x)?.length) {
      const y = graph.get(x)?.pop();
      if (y != null) {
        search(y);
      }
    }

    result.push(x);
  };

  pairs.forEach((pair, i) => {
    const [x, y] = pair;
    edgeCount.set(x, (edgeCount.get(x) || 0) + 1);
    edgeCount.set(y, (edgeCount.get(y) || 0) - 1);

    if (graph.has(x)) {
      graph.get(x)?.push(y);
    } else {
      graph.set(x, [y]);
    }
  });

  let start: number = pairs[0][0];
  [...edgeCount.keys()].forEach((num) => {
    const row = edgeCount.get(num);
    if (row != null && row === 1) {
      start = num;
    }
  });

  search(start);

  const reverse: number[][] = [];
  for (let i = result.length - 1; i >= 1; i -= 1) {
    reverse.push([result[i], result[i - 1]]);
  }

  return reverse;
};