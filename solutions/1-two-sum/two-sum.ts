// TypeScript

function twoSum(nums: number[], target: number): number[] {
    const ht = new Map<number, number>();
    
    for (let i = 0; i < nums.length; i++) {
        const num = nums[i];
        
        if (ht.has(target - num)) {
            return [ht.get(target - num)!, i];
        }
        
        ht.set(num, i);
    }
    
    return [];
}