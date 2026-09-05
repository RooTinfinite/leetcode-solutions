var firstStableIndex = function (nums, k) {
    const n = nums.length;
    const minValue = new Array(n);
    minValue[n - 1] = nums[n - 1];
    for (let i = n - 2; i >= 0; i--) {
        minValue[i] = Math.min(minValue[i + 1], nums[i]);
    }

    let maxValue = 0;
    for (let i = 0; i < n; i++) {
        maxValue = Math.max(maxValue, nums[i]);
        if (maxValue - minValue[i] <= k) {
            return i;
        }
    }
    return -1;
};