func countCommas(n int64) int64 {
	var p int64 = 1000
	var res int64 = 0
	for p <= n {
		res += n - p + 1
		p *= 1000
	}
	return res
}