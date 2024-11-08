// JavaScript

var getMaximumXor = function(nums, maximumBit) {
    const mask = (1 << maximumBit) - 1;
    const n = nums.length;
    const res = new Array(n);
    let curr = 0;
    
    for(let i = 0; i < n; i++) {
        curr ^= nums[i];
        res[n-i-1] = (~curr & mask);
    }
    
    return res;
};