func isInterleave(s1 string, s2 string, s3 string) bool {
    if len(s3) != len(s1)+len(s2) {
        return false
    }
    dp := make([]bool, len(s2)+1)
    for i := 0; i <= len(s1); i++ {
        for j := 0; j <= len(s2); j++ {
            if i == 0 && j == 0 {
                dp[j] = true
            } else if i == 0 {
                dp[j] = dp[j-1] && s2[j-1] == s3[i+j-1]
            } else if j == 0 {
                dp[j] = dp[j] && s1[i-1] == s3[i+j-1]
            } else {
                dp[j] = (dp[j] && s1[i-1] == s3[i+j-1]) || (dp[j-1] && s2[j-1] == s3[i+j-1])
            }
        }
    }
    return dp[len(s2)]
}