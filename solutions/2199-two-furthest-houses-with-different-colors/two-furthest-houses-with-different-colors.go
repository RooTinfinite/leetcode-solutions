func maxDistance(colors []int) int {
	n := len(colors)
	res := 0 // the maximum distance between two houses of different colors
	// traverse the indices of two houses and maintain the maximum distance
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if colors[i] != colors[j] {
				if j-i > res {
					res = j - i
				}
			}
		}
	}
	return res
}