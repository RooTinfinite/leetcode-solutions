function minimumSubarrayLength(nums: number[], k: number): number {
    if (k === 0) {
        return 1;
    }
    let shortest = nums.length + 1;
    const count = new Array(32).fill(0);
    let val = 0;
    let start = 0;
    
    for (let i = 0; i < nums.length; ++i) {
        let num = nums[i];
        val |= num;
        for (let ibit = 0; num !== 0; ++ibit) {
            count[ibit] += num & 1;
            num >>= 1;
        }
        while (val >= k && start < nums.length) {
            shortest = Math.min(shortest, i - start + 1);
            num = nums[start];
            ++start;
            for (let ibit = 0; num !== 0; ++ibit) {
                count[ibit] -= num & 1;
                if (count[ibit] === 0) {
                    val &= ~(1 << ibit);
                }
                num >>= 1;
            }
        }
    }
    return shortest === (nums.length + 1) ? -1 : shortest;
}