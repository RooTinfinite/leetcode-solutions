var countSpecialIntegers = function(nums) {
    // Intuition: go left to right, skip values that don't occur exactly 3 times
    // then check for an equally spaced triple with increasing distance
    const n = nums.length;
    let r = 0;
    const freq = new Array(100).fill(0);
    for (const c of nums) {
        freq[c - 1]++;
    }
    for (let i = 0; i < n; i++) {
        const c = nums[i];
        if (freq[c - 1] !== 3) continue;
        freq[c - 1] = -1;
        for (let distance = 1; i + (distance * 2) < n; distance++) {
            if (nums[i + distance] === c && nums[i + (distance * 2)] === c) {
                r++;
                break;
            }
        }
    }
    return r;
};