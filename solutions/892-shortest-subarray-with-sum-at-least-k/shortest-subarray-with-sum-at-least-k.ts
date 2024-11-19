function shortestSubarray(nums: number[], k: number): number {
    const n: number = nums.length;
    const sum: number[] = new Array(n + 1).fill(0);
    
    // Calculate prefix sum
    for (let i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + nums[i];
    }
    
    const q: number[] = new Array(n + 1).fill(0);
    let l: number = 0;
    let r: number = 0;
    let minLength: number = n + 1;
    
    for (let i = 0; i < sum.length; i++) {
        while (r > l && sum[i] >= sum[q[l]] + k) {
            minLength = Math.min(minLength, i - q[l]);
            l++;
        }
        
        while (r > l && sum[i] <= sum[q[r - 1]]) {
            r--;
        }
        
        q[r] = i;
        r++;
    }
    
    return minLength <= n ? minLength : -1;
}
