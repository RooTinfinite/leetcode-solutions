func maxTotalValue(nums []int, k int) int64 {
	m1, m2 := math.MaxInt, math.MinInt
	for _, x := range nums {
		m1 = min(m1, x)
		m2 = max(m2, x)
	}
	return int64(m2-m1) * int64(k)
}