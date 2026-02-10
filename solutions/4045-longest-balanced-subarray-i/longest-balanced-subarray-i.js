var longestBalanced = function (nums) {
    let len = 0;

    for (let i = 0; i < nums.length; i++) {
        const odd = new Map();
        const even = new Map();

        for (let j = i; j < nums.length; j++) {
            const c = nums[j] & 1 ? odd : even;

            c.set(nums[j], (c.get(nums[j]) ?? 0) + 1);

            if (odd.size == even.size) {
                len = Math.max(len, j - i + 1);
            }
        }
    }

    return len;
};