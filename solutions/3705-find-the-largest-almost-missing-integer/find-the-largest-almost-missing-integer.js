var largestInteger = function (nums, k) {
    let n = nums.length;
    if (n === k) {
        return Math.max(...nums);
    }
    let count = new Array(51).fill(0);
    for (let x of nums) {
        count[x]++;
    }
    if (k === 1) {
        for (let i = 50; i >= 0; --i) {
            if (count[i] === 1) {
                return i;
            }
        }
        return -1;
    }
    let res = -1;
    if (count[nums[0]] === 1) {
        res = Math.max(res, nums[0]);
    }
    if (count[nums[n - 1]] === 1) {
        res = Math.max(res, nums[n - 1]);
    }
    return res;
};