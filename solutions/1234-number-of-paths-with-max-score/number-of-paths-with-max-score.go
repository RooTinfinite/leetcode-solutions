func pathsWithMaxScore(board []string) []int {
	const MOD = 1000000007
	n := len(board)
	dp := make([][][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([][]int, n)
		for j := 0; j < n; j++ {
			dp[i][j] = []int{-1, 0}
		}
	}
	dp[n-1][n-1][0] = 0
	dp[n-1][n-1][1] = 1

	update := func(x, y, u, v int) {
		if u >= n || v >= n || dp[u][v][0] == -1 {
			return
		}
		if dp[u][v][0] > dp[x][y][0] {
			dp[x][y][0] = dp[u][v][0]
			dp[x][y][1] = dp[u][v][1]
		} else if dp[u][v][0] == dp[x][y][0] {
			dp[x][y][1] = (dp[x][y][1] + dp[u][v][1]) % MOD
		}
	}

	for i := n - 1; i >= 0; i-- {
		for j := n - 1; j >= 0; j-- {
			if !(i == n-1 && j == n-1) && board[i][j] != 'X' {
				update(i, j, i+1, j)
				update(i, j, i, j+1)
				update(i, j, i+1, j+1)
				if dp[i][j][0] != -1 {
					if board[i][j] == 'E' {
						dp[i][j][0] += 0
					} else {
						dp[i][j][0] += int(board[i][j] - '0')
					}
				}
			}
		}
	}

	if dp[0][0][0] != -1 {
		return []int{dp[0][0][0], dp[0][0][1] % MOD}
	}

	return []int{0, 0}
}