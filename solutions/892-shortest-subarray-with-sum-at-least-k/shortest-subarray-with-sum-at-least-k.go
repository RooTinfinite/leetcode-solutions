func shortestSubarray(nums []int, k int) int {
    n := len(nums)
    sum := make([]int64, n+1)
    
    for i := 0; i < n; i++ {
        sum[i+1] = sum[i] + int64(nums[i])
    }
    
    q := make([]int, n+1)
    l, r := 0, 0
    minLength := n + 1
    
    for i := 0; i < len(sum); i++ {
        for r > l && sum[i] >= sum[q[l]]+int64(k) {
            if i-q[l] < minLength {
                minLength = i - q[l]
            }
            l++
        }
        
        for r > l && sum[i] <= sum[q[r-1]] {
            r--
        }
        
        q[r] = i
        r++
    }
    
    if minLength <= n {
        return minLength
    }
    return -1
}