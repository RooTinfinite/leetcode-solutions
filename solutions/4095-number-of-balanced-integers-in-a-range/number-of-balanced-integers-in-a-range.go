func countBalanced(low int64, high int64) int64 {
	low -= 1
	dlow := make([]int, 0)
	dhigh := make([]int, 0)

	for low > 0 {
		dlow = append(dlow, int(low%10))
		low /= 10
	}

	for high > 0 {
		dhigh = append(dhigh, int(high%10))
		high /= 10
	}

	diff1 := len(dlow) - len(dhigh)
	diff2 := len(dhigh) - len(dlow)

	for i := 0; i < diff1; i++ {
		dhigh = append(dhigh, 0)
	}
	for i := 0; i < diff2; i++ {
		dlow = append(dlow, 0)
	}

	for i := 0; i < len(dlow)/2; i++ {
		dlow[i], dlow[len(dlow)-1-i] = dlow[len(dlow)-1-i], dlow[i]
		dhigh[i], dhigh[len(dlow)-1-i] = dhigh[len(dlow)-1-i], dhigh[i]
	}

	solve := func(pos, t, odd, even int, digit []int) int64 {
        dp := make([][][][]int64, len(digit))
        for i := 0; i < len(dp); i++ {
            dp[i] = make([][][]int64, 2)
            for j := 0; j < len(dp[i]); j++ {
                dp[i][j] = make([][]int64, 64)
                for k := 0; k < len(dp[i][j]); k++ {
                    dp[i][j][k] = make([]int64, 64)
                    for l := 0; l < len(dp[i][j][k]); l++ {
                        dp[i][j][k][l] = -1
                    }
                }
            }
        }
        
		var dfs func(pos, t, odd, even int, digit []int) int64
		dfs = func(pos, t, odd, even int, digit []int) (res int64) {
            if odd > 63 || even > 63 {return 0}
			if pos == len(digit) && odd == even {
				return 1
			}
			if pos == len(digit) {
				return 0
			}

            if dp[pos][t][odd][even] > -1 {
                return dp[pos][t][odd][even]
            }
            
			l, r := 0, 9
			if t == 1 {
				r = digit[pos]
			}

			for i := l; i <= r; i++ {
				var nt int
				if t == 1 && i == r {
					nt = 1
				}
				var ne, no int = even, odd

				if pos&1 == 0 {
					ne = even + i
				}
				if pos&1 == 1 {
					no = odd + i
				}

				res += dfs(pos+1, nt, no, ne, digit)
			}
			dp[pos][t][odd][even] = res
			return res
		}
		return dfs(0, 1, 0, 0, digit)
	}

	return solve(0, 1, 0, 0, dhigh) - solve(0, 1, 0, 0, dlow)
}
