var divideArray = function(nums, k) {
    nums.sort((a, b) => a - b);
    const ans = [];
    for (let i = 0; i < nums.length; i += 3) {
        if (nums[i + 2] - nums[i] > k) {
            return [];
        }
        ans.push([nums[i], nums[i + 1], nums[i + 2]]);
    }
    return ans;
};