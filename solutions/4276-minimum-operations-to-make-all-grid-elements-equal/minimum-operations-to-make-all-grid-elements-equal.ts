function minOperations(grid: number[][], k: number): number {
  const m = grid.length;
  const n = grid[0].length;

  const colSum = new Array<bigint>(n).fill(0n);
  const opsRing: bigint[][] = Array.from({ length: k }, () => new Array<bigint>(n).fill(0n));

  let hasCandidate = false;
  let candidateX = 0n;

  let sumOps0 = 0n;
  let sumOps1 = 0n;
  let minX = BigInt(Number.MIN_SAFE_INTEGER) * 1000n;

  for (let i = 0; i < m; i++) {
    if (i >= k) {
      const evictRow = i % k;
      for (let j = 0; j < n; j++) {
        colSum[j] -= opsRing[evictRow][j];
        opsRing[evictRow][j] = 0n;
      }
    }

    let windowSum = 0n;

    for (let j = 0; j < n; j++) {
      windowSum += colSum[j];
      const req0 = -BigInt(grid[i][j]) - windowSum;

      if (i <= m - k && j <= n - k) {
        opsRing[i % k][j] = req0;
        colSum[j] += req0;
        windowSum += req0;

        const o1 = i % k === 0 && j % k === 0 ? 1n : 0n;
        sumOps0 += req0;
        sumOps1 += o1;

        if (o1 === 1n) {
          if (-req0 > minX) minX = -req0;
        } else {
          if (req0 < 0n) return -1;
        }
      } else {
        const r1 =
          Math.floor(i / k) * k > m - k || Math.floor(j / k) * k > n - k ? 1n : 0n;

        if (r1 !== 0n) {
          const x = -req0;
          if (!hasCandidate) {
            candidateX = x;
            hasCandidate = true;
          } else if (candidateX !== x) {
            return -1;
          }
        } else {
          if (req0 !== 0n) return -1;
        }
      }

      if (j >= k - 1) {
        windowSum -= colSum[j - k + 1];
      }
    }
  }

  if (hasCandidate) {
    if (candidateX < minX) return -1;
  } else {
    candidateX = minX;
  }

  const result = sumOps0 + candidateX * sumOps1;

  if (result > BigInt(Number.MAX_SAFE_INTEGER) || result < BigInt(Number.MIN_SAFE_INTEGER)) {
    throw new RangeError(`Result ${result} exceeds safe integer range`);
  }

  return Number(result);
}