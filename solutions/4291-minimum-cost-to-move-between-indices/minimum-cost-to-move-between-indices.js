/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {number[]}
 */
var minCost = function(nums, queries) {
    let n = nums.length;
    let len = queries.length;

    let pre = new Array(n).fill(0);
    let suff = new Array(n).fill(0);

    for (let i = 0; i < n - 1; i++) {
        let diffFromRight = nums[i + 1] - nums[i];
        let diffFromLeft = (i > 0)
            ? nums[i] - nums[i - 1]
            : Number.MAX_SAFE_INTEGER;

        pre[i + 1] = pre[i] + (diffFromRight < diffFromLeft ? 1 : diffFromRight);
    }

    for (let i = n - 1; i > 0; i--) {
        let diffFromLeft = nums[i] - nums[i - 1];
        let diffFromRight = (i < n - 1)
            ? nums[i + 1] - nums[i]
            : Number.MAX_SAFE_INTEGER;

        suff[i - 1] = suff[i] + (diffFromLeft <= diffFromRight ? 1 : diffFromLeft);
    }

    let ans = new Array(len);

    for (let i = 0; i < len; i++) {
        let l = queries[i][0];
        let r = queries[i][1];

        if (l <= r) {
            ans[i] = pre[r] - pre[l];
        } else {
            ans[i] = suff[r] - suff[l];
        }
    }

    return ans;
};