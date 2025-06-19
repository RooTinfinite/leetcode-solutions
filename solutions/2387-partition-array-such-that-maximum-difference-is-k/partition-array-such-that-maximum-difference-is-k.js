function partitionArray(nums, k) {
    nums.sort((a, b) => a - b);
    let ans = 1;
    let min = nums[0];
    
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] - min > k) {
            ans++;
            min = nums[i];
        }
    }
    
    return ans;
}