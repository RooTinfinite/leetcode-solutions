var maxSelectedElements = function (nums) {
    nums.sort((a, b) => a - b);
    const dp = new Map();
    let ans = 0;
    for (const x of nums) {
        dp.set(x + 1, Math.max(dp.get(x + 1) ?? 0, (dp.get(x) ?? 0) + 1));
        dp.set(x, Math.max(dp.get(x) ?? 0, (dp.get(x - 1) ?? 0) + 1));
        ans = Math.max(ans, dp.get(x), dp.get(x + 1));
    }
    return ans;
};