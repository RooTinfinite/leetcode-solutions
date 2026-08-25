function missingMultiple(nums: number[], k: number): number {
    const seen = new Set<number>(nums);
    let ans = k;
    while (seen.has(ans)) {
        ans += k;
    }
    return ans;
}