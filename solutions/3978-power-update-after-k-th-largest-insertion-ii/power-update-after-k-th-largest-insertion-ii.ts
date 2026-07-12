function powerUpdate(nums: number[], p: number, queries: number[][]): number[] {
    const MOD = 1_000_000_007n;

    const allValues = new Set<number>();
    for (const v of nums) allValues.add(v);
    for (const [v] of queries) allValues.add(v);

    const sorted = Array.from(allValues).sort((a, b) => a - b);
    const valueToIdx = new Map<number, number>();
    sorted.forEach((v, i) => valueToIdx.set(v, i + 1));

    const size = sorted.length;
    const bit = new Int32Array(size + 1);

    let logSize = 1;
    while (logSize * 2 <= size) logSize *= 2;

    const update = (i: number): void => {
        for (; i <= size; i += i & -i) bit[i]++;
    };

    // Возвращает 1-индексированную позицию k-го наименьшего по cumulative count
    const findKthSmallest = (k: number): number => {
        let pos = 0;
        for (let mask = logSize; mask > 0; mask >>= 1) {
            const next = pos + mask;
            if (next <= size && bit[next] < k) {
                pos = next;
                k -= bit[next];
            }
        }
        return pos + 1;
    };

    let total = 0;
    for (const v of nums) {
        update(valueToIdx.get(v)!);
        total++;
    }

    const powMod = (base: bigint, exp: bigint): bigint => {
        let result = 1n;
        base %= MOD;
        while (exp > 0n) {
            if (exp & 1n) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1n;
        }
        return result;
    };

    let currentP = BigInt(p);
    const ans: number[] = [];

    for (const [val, k] of queries) {
        update(valueToIdx.get(val)!);
        total++;
        // k-й по убыванию = (total - k + 1)-й по возрастанию
        const idx = findKthSmallest(total - k + 1);
        const x = sorted[idx - 1];
        currentP = powMod(currentP, BigInt(x));
        ans.push(Number(currentP));
    }

    return ans;
}