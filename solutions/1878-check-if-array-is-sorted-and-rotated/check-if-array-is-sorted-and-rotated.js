var check = function(nums) {
    let breaks = 0;
    const n = nums.length;

    for (let i = 0; i < n; i++) {
        if (nums[i] > nums[(i + 1) % n]) {
            breaks++;
        }
    }

    return breaks <= 1;
};