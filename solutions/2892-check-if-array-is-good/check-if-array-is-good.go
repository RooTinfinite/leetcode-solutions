func isGood(nums []int) bool {
	n := len(nums)
	count := make([]int, n)
	for _, a := range nums {
		if a < 1 || a >= n {
			return false
		}
		if a < n-1 && count[a] > 0 {
			return false
		}
		if a == n-1 && count[a] > 1 {
			return false
		}
		count[a]++
	}
	return true
}