var minBitwiseArray = function (nums) {
    for (let i = 0; i < nums.length; i++) {
        let x = nums[i];
        let res = -1;
        let d = 1;
        while ((x & d) !== 0) {
            res = x - d;
            d <<= 1;
        }
        nums[i] = res;
    }
    return nums;
};