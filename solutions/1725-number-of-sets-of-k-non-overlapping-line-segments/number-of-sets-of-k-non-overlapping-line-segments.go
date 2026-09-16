func numberOfSets(n int, k int) int {
	const mod = 1000000007
	dp := make([]int, n)
	prefixSums := make([]int, n+1)
	for j := 0; j < n; j++ {
		dp[j] = 1
		prefixSums[j+1] = (prefixSums[j] + dp[j]) % mod
	}
	for i := 1; i <= k; i++ {
		dp[0] = 0
		for j := 1; j < n; j++ {
			dp[j] = (dp[j-1] + prefixSums[j]) % mod
		}
		for j := 0; j < n; j++ {
			prefixSums[j+1] = (prefixSums[j] + dp[j]) % mod
		}
	}
	return dp[n-1]
}