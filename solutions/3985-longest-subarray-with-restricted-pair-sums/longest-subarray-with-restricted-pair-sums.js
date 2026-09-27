/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubarray = function(nums) {
    const n = nums.length;
    let ans = 0, l = 0;
    const hash = new Int32Array(501);
    
    const isValid = (target) => {
        const half = Math.floor(target / 2);
        for (let i = 1; i <= half; ++i) {
            if (i === target - i) {
                if (hash[i] >= 2) return false;
            } else {
                if (hash[i] > 0 && hash[target - i] > 0) return false;
            }
        }
        for (let i = 1; i + target <= 500; ++i) {
            if (hash[i] > 0 && hash[i + target] > 0) return false;
        }
        return true;
    };
    
    for (let r = 0; r < n; ++r) {
        while (!isValid(nums[r])) {
            hash[nums[l]]--;
            l++;
        }
        hash[nums[r]]++;
        if (r - l + 1 > ans) {
            ans = r - l + 1;
        }
    }
    
    return ans;
};