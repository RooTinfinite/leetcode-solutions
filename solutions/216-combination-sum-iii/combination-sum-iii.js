var combinationSum3 = function (k, n) {
    let arr = [1, 2, 3, 4, 5, 6, 7, 8, 9];
    let ans = [];
    function helper(sum, ar, i) {
        if (ar.length === k && sum === n) {
            ans.push(ar);
            return;
        }
        if (i >= n) {
            if (ar.length === k && sum === n) {
                ans.push(ar);
                return;
            }
            return;
        }
        for (let j = i; j < arr.length; j++) {
            helper(sum + arr[j], [...ar, arr[j]], j + 1);
        }
    }
    helper(0, [], 0);
    return ans;
};