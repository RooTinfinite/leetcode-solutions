/**
 * @param {number[]} power
 * @return {number}
 */
var maximumTotalDamage = function(nums) {
    nums.sort((a, b) => a - b);
    let dp = [];
    let preMax = 0;
    let ans = 0;
    let dpIdx = 0;

    for (let i = 0; i < nums.length;) {
        while (dpIdx < dp.length && dp[dpIdx][0] + 2 < nums[i]) {
            preMax = Math.max(preMax, dp[dpIdx][1]);
            dpIdx++;
        }

        let j = i;
        let cur = 0;
        while (j < nums.length && nums[j] === nums[i]) {
            cur += nums[j];
            j++;
        }

        ans = Math.max(ans, cur + preMax);
        dp.push([nums[i], cur + preMax]);
        i = j;
    }

    return ans;
};