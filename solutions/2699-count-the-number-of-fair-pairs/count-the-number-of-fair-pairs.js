var countFairPairs = function(nums, lower, upper) {
    const binSearch = (l, r, target) => {
        while (l <= r) {
            const m = Math.floor((l + r) / 2);
            if (nums[m] >= target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return r;
    };
    
    nums.sort((a, b) => a - b);
    let res = 0;
    
    for (let i = 0; i < nums.length; i++) {
        const low = lower - nums[i];
        const up = upper - nums[i];
        res += (
            binSearch(i + 1, nums.length - 1, up + 1) -
            binSearch(i + 1, nums.length - 1, low)
        );
    }
    
    return res;
};