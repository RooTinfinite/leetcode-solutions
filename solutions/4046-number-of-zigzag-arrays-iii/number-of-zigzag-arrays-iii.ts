function zigZagArrays(n: number, l: number, r: number): number {
  const MOD = 1000000007n;
  const m = BigInt(r - l + 1);
  const d = n;

  const modPow = (a: bigint, e: bigint): bigint => {
    let res = 1n;
    while (e > 0n) {
      if (e & 1n) res = (res * a) % MOD;
      a = (a * a) % MOD;
      e >>= 1n;
    }
    return res;
  };

  const calc = (k: number): bigint => {
    if (k === 0) return 0n;

    let up = Array<bigint>(k).fill(0n);
    let down = Array<bigint>(k).fill(0n);

    for (let v = 0; v < k; v++) {
      up[v] = BigInt(v);
      down[v] = BigInt(k - 1 - v);
    }

    for (let len = 3; len <= n; len++) {
      const nextUp = Array<bigint>(k).fill(0n);
      const nextDown = Array<bigint>(k).fill(0n);

      let pref = 0n;
      for (let v = 0; v < k; v++) {
        nextUp[v] = pref;
        pref = (pref + down[v]) % MOD;
      }

      let suff = 0n;
      for (let v = k - 1; v >= 0; v--) {
        nextDown[v] = suff;
        suff = (suff + up[v]) % MOD;
      }

      up = nextUp;
      down = nextDown;
    }

    let res = 0n;
    for (let i = 0; i < k; i++) res = (res + up[i] + down[i]) % MOD;
    return res;
  };

  const y = Array.from({ length: d + 1 }, (_, i) => calc(i));

  if (m <= BigInt(d)) return Number(y[Number(m)]);

  const fact = Array<bigint>(d + 1).fill(1n);
  const invFact = Array<bigint>(d + 1).fill(1n);

  for (let i = 1; i <= d; i++) fact[i] = (fact[i - 1] * BigInt(i)) % MOD;
  invFact[d] = modPow(fact[d], MOD - 2n);
  for (let i = d - 1; i >= 0; i--) invFact[i] = (invFact[i + 1] * BigInt(i + 1)) % MOD;

  const x = m % MOD;
  let all = 1n;
  for (let i = 0; i <= d; i++) all = (all * ((x - BigInt(i) + MOD) % MOD)) % MOD;

  let ans = 0n;
  for (let i = 0; i <= d; i++) {
    let denomInv = (invFact[i] * invFact[d - i]) % MOD;
    if ((d - i) % 2 === 1) denomInv = (MOD - denomInv) % MOD;

    const term = (((y[i] * all) % MOD) * modPow((x - BigInt(i) + MOD) % MOD, MOD - 2n)) % MOD;
    ans = (ans + term * denomInv) % MOD;
  }

  return Number(ans);
}