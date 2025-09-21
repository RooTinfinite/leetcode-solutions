function closestTarget(W, T, s) {
  let a = Number.MAX_SAFE_INTEGER, n = W.length;
  for (let i = 0; i < n; i++) {
    if (W[i] === T) {
      const d = Math.abs(i - s);
      a = Math.min(a, Math.min(d, n - d));
    }
  }
  return a === Number.MAX_SAFE_INTEGER ? -1 : a;
}