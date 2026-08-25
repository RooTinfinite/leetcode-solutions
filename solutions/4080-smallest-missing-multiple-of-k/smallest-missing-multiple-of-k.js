var missingMultiple = function (nums, k) {
    const seen = new Set(nums);
    let ans = k;
    while (seen.has(ans)) {
        ans += k;
    }
    return ans;
};