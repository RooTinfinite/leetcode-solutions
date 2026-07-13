const limitOccurrences = (nums, k) => {
    let i = 0;
    
    for (const n of nums)
        if (i < k || n !== nums[i - k])
            nums[i++] = n;
            
    while (nums.length > i) nums.pop();
        
    return nums;
};