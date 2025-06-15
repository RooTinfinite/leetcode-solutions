function removeCoveredIntervals(intervals: number[][]): number {
  intervals.sort(([a, b], [c, d]) => a - c || d - b);

  let res = 0;
  let end = Number.MIN_SAFE_INTEGER;

  intervals.forEach(([, b]) => {
    if (b > end) res++;

    end = Math.max(end, b);
  });

  return res;
}