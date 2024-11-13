// TypeScript

function binSearch(nums: number[], l: number, r: number, target: number): number {
    while (l <= r) {
        const m = l + Math.floor((r - l) / 2);
        if (nums[m] >= target) r = m - 1;
        else l = m + 1;
    }
    return r;
}

function countFairPairs(nums: number[], lower: number, upper: number): number {
    nums.sort((a, b) => a - b);
    let res = 0;
    for (let i = 0; i < nums.length; i++) {
        const low = lower - nums[i];
        const up = upper - nums[i];
        res += binSearch(nums, i + 1, nums.length - 1, up + 1) - 
               binSearch(nums, i + 1, nums.length - 1, low);
    }
    return res;
}