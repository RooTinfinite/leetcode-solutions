function maxProfit(nums: number[]): number {
    let minPro: number = Number.MAX_SAFE_INTEGER;
    let maxPro: number = 0;
    
    for (let i = 0; i < nums.length; i++) {
        minPro = Math.min(nums[i], minPro);
        maxPro = Math.max(maxPro, nums[i] - minPro);
    }
    
    return maxPro;
}