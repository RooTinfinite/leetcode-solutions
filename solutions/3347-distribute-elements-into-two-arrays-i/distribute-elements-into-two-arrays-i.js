var resultArray = function (nums) {
    const n = nums.length;
    const arr = new Array(n);
    arr[0] = nums[0];
    arr[n - 1] = nums[1];
    let idx = 0,
        revIdx = n - 1;
    for (let i = 2; i < n; i++) {
        if (arr[idx] > arr[revIdx]) {
            arr[++idx] = nums[i];
        } else {
            arr[--revIdx] = nums[i];
        }
    }
    for (let l = revIdx, r = n - 1; l < r; l++, r--) {
        [arr[l], arr[r]] = [arr[r], arr[l]];
    }
    return arr;
};