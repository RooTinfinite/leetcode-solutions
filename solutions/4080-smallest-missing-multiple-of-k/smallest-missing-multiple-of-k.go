func missingMultiple(nums []int, k int) int {
	seen := make(map[int]bool)
	for _, num := range nums {
		seen[num] = true
	}
	ans := k
	for seen[ans] {
		ans += k
	}
	return ans
}