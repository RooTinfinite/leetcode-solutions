var minimumSize = function(nums, maxOperations) {
    const canDivide = (maxBalls) => {
        let ops = 0;
        for (const n of nums) {
            ops += Math.ceil(n / maxBalls) - 1;
            if (ops > maxOperations) return false;
        }
        return true;
    };
    
    let left = 1;
    let right = Math.max(...nums);
    let res = right;
    
    while (left < right) {
        const mid = left + Math.floor((right - left) / 2);
        if (canDivide(mid)) {
            right = mid;
            res = right;
        } else {
            left = mid + 1;
        }
    }
    return res;
};