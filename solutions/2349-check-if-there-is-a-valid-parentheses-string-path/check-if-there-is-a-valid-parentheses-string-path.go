func hasValidPath(grid [][]byte) bool {
	n := len(grid)
	m := len(grid[0])
	pathLen := n + m - 1

	if pathLen%2 == 1 {
		return false
	}
	if grid[0][0] != '(' || grid[n-1][m-1] != ')' {
		return false
	}

	dp := make([][]*big.Int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]*big.Int, m)
		for j := 0; j < m; j++ {
			dp[i][j] = new(big.Int)
		}
	}

	dp[0][0].SetInt64(1 << 1)

	tmp := new(big.Int)
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			change := -1
			if grid[i][j] == '(' {
				change = 1
			}

			if i > 0 {
				if change == 1 {
					tmp.Lsh(dp[i-1][j], 1)
				} else {
					tmp.Rsh(dp[i-1][j], 1)
				}
				dp[i][j].Or(dp[i][j], tmp)
			}

			if j > 0 {
				if change == 1 {
					tmp.Lsh(dp[i][j-1], 1)
				} else {
					tmp.Rsh(dp[i][j-1], 1)
				}
				dp[i][j].Or(dp[i][j], tmp)
			}
		}
	}

	return dp[n-1][m-1].Bit(0) == 1
}