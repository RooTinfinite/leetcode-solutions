function xorAfterQueries(nums: number[], queries: number[][]): number {
    const MOD = 1e9 + 7;
    for (const q of queries) {
        const [l, r, k, v] = q;
        for (let i = l; i <= r; i += k) {
            nums[i] = Number((BigInt(nums[i]) * BigInt(v)) % BigInt(MOD));
        }
    }

    let res = 0;
    for (const x of nums) {
        res ^= x;
    }
    return res;
}