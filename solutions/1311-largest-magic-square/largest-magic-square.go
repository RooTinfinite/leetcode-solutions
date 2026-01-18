func largestMagicSquare(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	// prefix sum of each row
	rowsum := make([][]int, m)
	for i := 0; i < m; i++ {
		rowsum[i] = make([]int, n)
		rowsum[i][0] = grid[i][0]
		for j := 1; j < n; j++ {
			rowsum[i][j] = rowsum[i][j-1] + grid[i][j]
		}
	}
	// prefix sum of each column
	colsum := make([][]int, m)
	for i := 0; i < m; i++ {
		colsum[i] = make([]int, n)
	}
	for j := 0; j < n; j++ {
		colsum[0][j] = grid[0][j]
		for i := 1; i < m; i++ {
			colsum[i][j] = colsum[i-1][j] + grid[i][j]
		}
	}

	for edge := min(m, n); edge >= 2; edge-- {
		// enumerate the top-left corner position (i,j) of the square
		for i := 0; i+edge <= m; i++ {
			for j := 0; j+edge <= n; j++ {
				// calculate the standard value
				stdsum := rowsum[i][j+edge-1]
				if j > 0 {
					stdsum -= rowsum[i][j-1]
				}
				check := true
				// check each row
				for ii := i + 1; ii < i+edge; ii++ {
					sum := rowsum[ii][j+edge-1]
					if j > 0 {
						sum -= rowsum[ii][j-1]
					}
					if sum != stdsum {
						check = false
						break
					}
				}
				if !check {
					continue
				}
				// check each column
				for jj := j; jj < j+edge; jj++ {
					sum := colsum[i+edge-1][jj]
					if i > 0 {
						sum -= colsum[i-1][jj]
					}
					if sum != stdsum {
						check = false
						break
					}
				}
				if !check {
					continue
				}
				// check the diagonal
				d1, d2 := 0, 0
				for k := 0; k < edge; k++ {
					d1 += grid[i+k][j+k]
					d2 += grid[i+k][j+edge-1-k]
				}
				if d1 == stdsum && d2 == stdsum {
					return edge
				}
			}
		}
	}
	return 1
}