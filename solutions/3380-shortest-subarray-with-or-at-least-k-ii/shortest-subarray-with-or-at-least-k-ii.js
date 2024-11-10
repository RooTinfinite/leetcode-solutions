var minimumSubarrayLength = function(nums, k) {
    let ans = Infinity;
    let d = new Map();
    
    for (let i = 0; i < nums.length; i++) {
        const temp = new Map();
        for (const [or_, left] of d.entries()) {
            temp.set(or_ | nums[i], left);
        }
        temp.set(nums[i], i);
        d = temp;
        
        for (const [or_, left] of d.entries()) {
            if (or_ >= k) {
                ans = Math.min(ans, i - left + 1);
            }
        }
    }
    
    return ans === Infinity ? -1 : ans;
};