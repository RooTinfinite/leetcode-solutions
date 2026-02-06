function minRemoval(nums: number[], k: number): number {
    const n = nums.length;
    nums.sort((a, b) => a - b);

    let ans = n;
    let right = 0;
    for (let left = 0; left < n; left++) {
        while (right < n && nums[right] <= nums[left] * k) {
            right++;
        }
        ans = Math.min(ans, n - (right - left));
    }

    return ans;
}