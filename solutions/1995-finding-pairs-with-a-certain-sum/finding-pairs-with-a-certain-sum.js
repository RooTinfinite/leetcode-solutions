var FindSumPairs = function (nums1, nums2) {
    this.nums1 = nums1;
    this.nums2 = nums2;
    this.cnt = new Map();
    for (const num of nums2) {
        this.cnt.set(num, (this.cnt.get(num) || 0) + 1);
    }
};

FindSumPairs.prototype.add = function (index, val) {
    const oldVal = this.nums2[index];
    this.cnt.set(oldVal, (this.cnt.get(oldVal) || 0) - 1);
    this.nums2[index] += val;
    const newVal = this.nums2[index];
    this.cnt.set(newVal, (this.cnt.get(newVal) || 0) + 1);
};

FindSumPairs.prototype.count = function (tot) {
    let ans = 0;
    for (const num of this.nums1) {
        const rest = tot - num;
        ans += this.cnt.get(rest) || 0;
    }
    return ans;
};