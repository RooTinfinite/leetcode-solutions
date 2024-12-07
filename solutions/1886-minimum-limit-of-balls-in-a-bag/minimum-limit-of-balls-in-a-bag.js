var minimumSize = function(nums, maxOperations) {
    let low = 1;
    let high = Math.max(...nums);
    
    while (low < high) {
        const mid = Math.floor((low + high) / 2);
        const ops = nums.reduce((sum, n) => sum + Math.floor((n - 1) / mid), 0);
        if (ops <= maxOperations) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return high;
};