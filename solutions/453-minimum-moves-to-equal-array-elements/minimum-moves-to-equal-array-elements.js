var minMoves = function(nums) {
    let sum = 0, min = Infinity;
    for (const x of nums) {
        sum += x;
        min = Math.min(min, x);
    }
    return sum - nums.length * min;
};