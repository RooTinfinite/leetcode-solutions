const maxTotalValue = (nums, k) => {
    const n = nums.length;
    const LUT = sparseTable(nums);
    const pq = new PriorityQueue(([a], [b]) => b - a);
    nums.forEach((_, i) => pq.enqueue([LUT.query(i, n), i, n]));

    let res = 0;
    while (pq.front()[0] && k--) {
        const [v, l, r] = pq.dequeue();
        res += v;
        pq.enqueue([LUT.query(l, r - 1), l, r - 1]);
    }

    return res;
};

const sparseTable = nums => {
    const n = nums.length;
    const bitW = 32 - Math.clz32(n);
    const min = Array.from({ length: bitW }, () => Array(n));
    const max = Array.from({ length: bitW }, () => Array(n));

    nums.forEach((cur, i) => { min[0][i] = max[0][i] = cur });

    for (let i = 1; i < bitW; i++)
        for (let j = 0; j + (1 << i) <= n; j++) {
            min[i][j] = Math.min(min[i - 1][j], min[i - 1][j + (1 << (i - 1))]);
            max[i][j] = Math.max(max[i - 1][j], max[i - 1][j + (1 << (i - 1))]);
        }

    return {
        query: (left, right) => {
            const k = 31 - Math.clz32(right - left);
            return Math.max(max[k][left], max[k][right - (1 << k)]) -
                   Math.min(min[k][left], min[k][right - (1 << k)]);
        }
    };
};