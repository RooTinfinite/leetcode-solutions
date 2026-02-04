function maxSumTrionic(nums: number[]): number {
    const n = nums.length;
    let res = -Infinity;
    for (let i = 1; i < n - 2; ) {
        let a = i, b = i;
        let net = nums[a];
        while (b + 1 < n && nums[b + 1] < nums[b]) {
            net += nums[++b];
        }
        if (b === a) { i++; continue; }
        let c = b;
        let left = 0, right = 0, lx = -Infinity, rx = -Infinity;
        while (a - 1 >= 0 && nums[a - 1] < nums[a]) {
            left += nums[--a];
            lx = Math.max(lx, left);
        }
        if (a === i) { i++; continue; }
        while (b + 1 < n && nums[b + 1] > nums[b]) {
            right += nums[++b];
            rx = Math.max(rx, right);
        }
        if (b === c) { i++; continue; }
        res = Math.max(res, lx + rx + net);
        i = b;
    }
    return res;
}