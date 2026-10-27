func createGrid(m, n int) []string {
	grid := make([]string, m)
	grid[0] = strings.Repeat(".", n)
	row := strings.Repeat("#", n-1) + "."
	for i := 1; i < m; i++ {
		grid[i] = row
	}
	return grid
}