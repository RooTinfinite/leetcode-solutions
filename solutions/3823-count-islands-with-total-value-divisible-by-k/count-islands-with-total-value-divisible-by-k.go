func countIslands(grid [][]int, k int) int {
	m, n := len(grid), len(grid[0])
	dirs := [5]int{-1, 0, 1, 0, -1}

	var dfs func(i, j int) int64
	dfs = func(i, j int) int64 {
		sum := int64(grid[i][j])
		grid[i][j] = 0
		for d := 0; d < 4; d++ {
			x := i + dirs[d]
			y := j + dirs[d+1]
			if x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > 0 {
				sum += dfs(x, y)
			}
		}
		return sum
	}

	ans := 0
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] > 0 && dfs(i, j)%int64(k) == 0 {
				ans++
			}
		}
	}
	return ans
}