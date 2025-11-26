func numberOfPaths(grid [][]int, k int) int {
	const MOD = 1000000007
	m, n := len(grid), len(grid[0])

	dp := make([][][]int64, m+1)
	for i := range dp {
		dp[i] = make([][]int64, n+1)
		for j := range dp[i] {
			dp[i][j] = make([]int64, k)
		}
	}

	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if i == 1 && j == 1 {
				dp[i][j][grid[0][0]%k] = 1
				continue
			}

			value := grid[i-1][j-1] % k
			for r := 0; r < k; r++ {
				prevMod := (r - value + k) % k
				dp[i][j][r] = (dp[i-1][j][prevMod] + dp[i][j-1][prevMod]) % MOD
			}
		}
	}

	return int(dp[m][n][0])
}