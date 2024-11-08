func getMaximumXor(nums []int, maximumBit int) []int {
    mask := (1 << maximumBit) - 1
    n := len(nums)
    res := make([]int, n)
    curr := 0
    
    for i := 0; i < n; i++ {
        curr ^= nums[i]
        res[n-i-1] = ^curr & mask
    }
    
    return res
}