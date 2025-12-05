function countPartitions(nums) {
    const totalSum = nums.reduce((a, b) => a + b, 0);
    return totalSum % 2 === 0 ? nums.length - 1 : 0;
}