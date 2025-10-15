var minRemoval = function(nums, k) {
    nums.sort((a, b) => a - b);
    let left = 0, maxSize = 0;

    for (let right = 0; right < nums.length; right++) {
        while (nums[right] > k * nums[left]) left++;
        maxSize = Math.max(maxSize, right - left + 1);
    }
    return nums.length - maxSize;
};