func min(x, y, z int) int {
    m := x
    if y < m {
        m = y
    }
    if z < m {
        m = z
    }
    return m
}

func minDistance(word1 string, word2 string) int {
    word1Length := len(word1)
    word2Length := len(word2)
    if word1Length == 0 {
        return word2Length
    }
    if word2Length == 0 {
        return word1Length
    }
    dp := make([][]int, word1Length+1)
    for i := range dp {
        dp[i] = make([]int, word2Length+1)
    }
    for word1Index := 1; word1Index <= word1Length; word1Index++ {
        dp[word1Index][0] = word1Index
    }
    for word2Index := 1; word2Index <= word2Length; word2Index++ {
        dp[0][word2Index] = word2Index
    }
    for word1Index := 1; word1Index <= word1Length; word1Index++ {
        for word2Index := 1; word2Index <= word2Length; word2Index++ {
            if word2[word2Index-1] == word1[word1Index-1] {
                dp[word1Index][word2Index] = dp[word1Index-1][word2Index-1]
            } else {
                dp[word1Index][word2Index] = min(dp[word1Index-1][word2Index], dp[word1Index][word2Index-1], dp[word1Index-1][word2Index-1]) + 1
            }
        }
    }
    return dp[word1Length][word2Length]
}