func countBits(n int) []int {
    ans := make([]int, n + 1)
    for i := 1; i <= n; i++ {
        ans[i] = ans[i >> 1] + (i & 1)
    }
    return ans
}