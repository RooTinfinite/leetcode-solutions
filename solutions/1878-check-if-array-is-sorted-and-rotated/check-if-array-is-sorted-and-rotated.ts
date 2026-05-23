function check(nums: number[]): boolean {
    const n = nums.length;
    let breaks = 0;

    for (let i = 0; i < n; i++) {
        if (nums[i] > nums[(i + 1) % n]) {
            breaks++;
        }
    }

    return breaks <= 1;
}