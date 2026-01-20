var minBitwiseArray = function (nums) {
    const result = new Array(nums.length);

    for (let i = 0; i < nums.length; i++) {
        const original = nums[i];
        let candidate = -1;

        for (let j = 1; j < original; j++) {
            if ((j | (j + 1)) === original) {
                candidate = j;
                break;
            }
        }

        result[i] = candidate;
    }

    return result;
};