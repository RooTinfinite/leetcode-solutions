func climbStairs(n int, costs []int) int {
	a, b, c := 0, 0, 0
	for i := 0; i < n; i++ {
		nxt := min(min(a+9, b+4), c+1) + costs[i]
		a, b, c = b, c, nxt
	}
	return c
}