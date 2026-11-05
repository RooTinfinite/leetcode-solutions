var minDeletions = function(nums) {
    let k = 0;

    for (let i = 1; i < nums.length; i++) {
        if ((nums[i - 1] ^ nums[i]) === 0) {
            k++;
        }
    }

    return k;
};