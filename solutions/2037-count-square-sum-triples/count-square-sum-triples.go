func countTriples(n int) int {
	res := 0
	// enumerate a and b
	for a := 1; a <= n; a++ {
		for b := 1; b <= n; b++ {
			// determine if it meets the requirements
			c := int(math.Sqrt(float64(a*a + b*b + 1)))
			if c <= n && c*c == a*a+b*b {
				res++
			}
		}
	}
	return res
}