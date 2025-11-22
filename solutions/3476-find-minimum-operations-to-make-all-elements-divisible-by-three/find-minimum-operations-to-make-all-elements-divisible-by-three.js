var minimumOperations = function (nums) {
    return nums.reduce((pre, v) => (pre += Math.min(3 - (v % 3), v % 3)), 0);
};