function constructTransformedArray(nums: number[]): number[] {
    const n = nums.length;
    const res: number[] = new Array(n);
    for (let i = 0; i < n; i++) {
        res[i] = nums[(((i + nums[i]) % n) + n) % n];
    }
    return res;
}