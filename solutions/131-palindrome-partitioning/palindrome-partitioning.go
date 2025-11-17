func partition(s string) [][]string {
    len_s := len(s)
    dp := make([][]bool, len_s)
    for i := range dp {
        dp[i] = make([]bool, len_s)
    }
    result := make([][]string, 0)
    dfs(&result, s, 0, make([]string, 0), dp)
    return result
}

func dfs(
    result *[][]string,
    s string,
    start int,
    currentList []string,
    dp [][]bool,
) {
    if start >= len(s) {
        newList := make([]string, len(currentList))
        copy(newList, currentList)
        *result = append(*result, newList)
    } else {
        for end := start; end < len(s); end++ {
            if s[start] == s[end] && (end-start <= 2 || dp[start+1][end-1]) {
                dp[start][end] = true
                currentList = append(currentList, s[start:end+1])
                dfs(result, s, end+1, currentList, dp)
                currentList = currentList[:len(currentList)-1]
            }
        }
    }
}