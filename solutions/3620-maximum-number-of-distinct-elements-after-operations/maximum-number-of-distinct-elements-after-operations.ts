function maxDistinctElements(nums: number[], k: number): number {
    nums.sort((a, b) => a - b);
    let cnt = 0;
    let prev = -Number.MAX_SAFE_INTEGER;

    for (const num of nums) {
        const curr = Math.min(Math.max(num - k, prev + 1), num + k);
        if (curr > prev) {
            cnt++;
            prev = curr;
        }
    }
    return cnt;
}