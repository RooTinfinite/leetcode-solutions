func numDistinct(s string, t string) int {
    M := len(s)
    N := len(t)
    dp := make([]int, N)
    prev := 1
    for i := M - 1; i >= 0; i-- {
        prev = 1
        for j := N - 1; j >= 0; j-- {
            old_dpj := dp[j]
            if s[i] == t[j] {
                dp[j] += prev
            }
            prev = old_dpj
        }
    }
    return dp[0]
}