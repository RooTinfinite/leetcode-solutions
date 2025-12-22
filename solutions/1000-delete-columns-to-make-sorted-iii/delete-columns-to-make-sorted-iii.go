package main

func minDeletionSize(strs []string) int {
	n := len(strs[0])
	m := len(strs)
	dp := make([]int, n)
	for i := 0; i < n; i++ {
		dp[i] = 1
	}

	for i := 1; i < n; i++ {
		for j := 0; j < i; j++ {
			ok := true
			for r := 0; r < m; r++ {
				if strs[r][j] > strs[r][i] {
					ok = false
					break
				}
			}
			if ok && dp[i] < dp[j]+1 {
				dp[i] = dp[j] + 1
			}
		}
	}

	mx := 0
	for _, v := range dp {
		if v > mx {
			mx = v
		}
	}
	return n - mx
}