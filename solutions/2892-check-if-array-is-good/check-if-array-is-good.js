var isGood = function (nums) {
    const n = nums.length;
    const count = new Array(n).fill(0);
    for (const a of nums) {
        if (a >= n) {
            return false;
        }
        if (a < n - 1 && count[a] > 0) {
            return false;
        }
        if (a === n - 1 && count[a] > 1) {
            return false;
        }
        count[a]++;
    }
    return true;
};