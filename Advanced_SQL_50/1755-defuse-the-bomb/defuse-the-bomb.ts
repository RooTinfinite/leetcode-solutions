function decrypt(circ: number[], k: number): number[] {
    const n: number = circ.length;
    const result: number[] = new Array(n).fill(0);

    if (k === 0) return result;

    let wSum: number = 0;
    const start: number = k > 0 ? 1 : n + k;
    const end: number = k > 0 ? k : n - 1;

    for (let i = start; i <= end; i++) {
        wSum += circ[i % n];
    }

    for (let i = 0; i < n; i++) {
        result[i] = wSum;
        wSum -= circ[(start + i) % n];
        wSum += circ[(end + i + 1) % n];
    }
    return result;
};

