func numberOfWays(n int, x int) int {
	const mod = 1_000_000_007
	dp := make([]int, n+1)
	dp[0] = 1
	for i := 1; i <= n; i++ {
		val := int(math.Pow(float64(i), float64(x)))
		if val > n {
			break
		}
		for j := n; j >= val; j-- {
			dp[j] = (dp[j] + dp[j-val]) % mod
		}
	}
	return dp[n]
}