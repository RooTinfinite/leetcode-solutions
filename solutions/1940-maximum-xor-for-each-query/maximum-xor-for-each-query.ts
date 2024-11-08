// TypeScript

function getMaximumXor(nums: number[], maximumBit: number): number[] {
    const mask: number = (1 << maximumBit) - 1;
    const n: number = nums.length;
    const res: number[] = new Array(n);
    let curr: number = 0;
    
    for(let i = 0; i < n; i++) {
        curr ^= nums[i];
        res[n-i-1] = (~curr & mask);
    }
    
    return res;
}