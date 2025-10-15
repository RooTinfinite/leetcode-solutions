function countXorSubarrays(nums: number[], k: number): number {
  if (k <= 0) {
    const n = nums.length;
    return (n * (n + 1)) / 2;
  }

  const maxVal = nums.reduce((a, b) => (a | b) >>> 0, 0) | k;
  let MAX_BIT = 31 - Math.clz32(maxVal >>> 0);
  if (MAX_BIT < 0) MAX_BIT = 0;

  const N = (nums.length + 1) * (MAX_BIT + 2); // upper bound for nodes
  const child0 = new Int32Array(N).fill(-1);
  const child1 = new Int32Array(N).fill(-1);
  const count = new Int32Array(N);

  let nodeCount = 1; // root index = 0

  const insert = (num: number) => {
    let node = 0;
    for (let i = MAX_BIT; i >= 0; i--) {
      const bit = (num >>> i) & 1;
      if (bit === 0) {
        if (child0[node] === -1) child0[node] = nodeCount++;
        node = child0[node];
      } else {
        if (child1[node] === -1) child1[node] = nodeCount++;
        node = child1[node];
      }
      count[node]++;
    }
  };

  const countLessThanK = (num: number, kk: number): number => {
    let node = 0;
    let cnt = 0;
    for (let i = MAX_BIT; i >= 0 && node !== -1; i--) {
      const nBit = (num >>> i) & 1;
      const kBit = (kk >>> i) & 1;
      if (kBit === 1) {
        const same = nBit === 0 ? child0[node] : child1[node];
        if (same !== -1) cnt += count[same];
        node = nBit === 0 ? child1[node] : child0[node];
      } else {
        node = nBit === 0 ? child0[node] : child1[node];
      }
    }
    return cnt;
  };

  let prefix = 0;
  let res = 0;
  let seen = 0;

  insert(0);
  seen = 1;

  for (const x of nums) {
    prefix ^= x;
    res += seen - countLessThanK(prefix, k);
    insert(prefix);
    seen++;
  }

  return res;
}