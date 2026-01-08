var maxDotProduct = function(nums1, nums2) {
    let m = nums1.length, n = nums2.length;
    let current = new Array(n + 1).fill(Number.MIN_SAFE_INTEGER);
    let previous = new Array(n + 1).fill(Number.MIN_SAFE_INTEGER);

    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            let curr_product = nums1[i - 1] * nums2[j - 1];
            current[j] = Math.max(curr_product, previous[j], current[j - 1], curr_product + Math.max(0, previous[j - 1]));
        }
        [current, previous] = [previous, current];
    }
    return previous[n];
};