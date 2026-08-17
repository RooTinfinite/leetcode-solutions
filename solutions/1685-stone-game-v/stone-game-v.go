func stoneGameV(stoneValue []int) int {
	n := len(stoneValue)
	f := make([][]int, n)
	maxl := make([][]int, n)
	maxr := make([][]int, n)
	for i := 0; i < n; i++ {
		f[i] = make([]int, n)
		maxl[i] = make([]int, n)
		maxr[i] = make([]int, n)
	}

	for left := n - 1; left >= 0; left-- {
		maxl[left][left] = stoneValue[left]
		maxr[left][left] = stoneValue[left]
		total := stoneValue[left]
		suml := 0
		i := left - 1
		for right := left + 1; right < n; right++ {
			total += stoneValue[right]
			for i+1 < right && (suml+stoneValue[i+1])*2 <= total {
				suml += stoneValue[i+1]
				i++
			}
			if left <= i {
				f[left][right] = max(f[left][right], maxl[left][i])
			}
			if i+1 < right {
				f[left][right] = max(f[left][right], maxr[i+2][right])
			}
			if suml*2 == total {
				f[left][right] = max(f[left][right], maxr[i+1][right])
			}
			maxl[left][right] = max(maxl[left][right-1], total+f[left][right])
			maxr[left][right] = max(maxr[left+1][right], total+f[left][right])
		}
	}

	return f[0][n-1]
}