// JavaScript

var merge = function(nums1, m, nums2, n) {
    for (let j = 0, i = m; j < n; j++, i++) {
        nums1[i] = nums2[j];
    }
    nums1.sort((a, b) => a - b);
};