var countConsistent = function(nums) {
    const n = nums.length;
    let cnt = 0;
    for (let i = 0; i < n; i++) {
        let add = nums[i];
        let minVal = nums[i];
        for (let j = i; j < n; j++) {
            add &= nums[j];
            if (nums[j] < minVal) {
                minVal = nums[j];
            }
            if (add === minVal) {
                cnt++;
            }
        }
    }
    return cnt;
};