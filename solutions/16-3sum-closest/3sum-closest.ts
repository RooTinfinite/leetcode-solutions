function threeSumClosest(nums: number[], target: number): number {
    let diff = Number.MAX_SAFE_INTEGER,
        sz = nums.length;
    nums.sort((a, b) => a - b);
    for (let i = 0; i < sz && diff != 0; ++i) {
        for (let j = i + 1; j < sz - 1; ++j) {
            let complement = target - nums[i] - nums[j];
            let lo = j + 1,
                hi = sz;
            while (lo < hi) {
                let mid = Math.floor(lo + (hi - lo) / 2);
                if (nums[mid] <= complement) lo = mid + 1;
                else hi = mid;
            }
            let hi_idx = lo,
                lo_idx = lo - 1;
            if (
                hi_idx < sz &&
                Math.abs(complement - nums[hi_idx]) < Math.abs(diff)
            )
                diff = complement - nums[hi_idx];
            if (
                lo_idx > j &&
                Math.abs(complement - nums[lo_idx]) < Math.abs(diff)
            )
                diff = complement - nums[lo_idx];
        }
    }
    return target - diff;
}