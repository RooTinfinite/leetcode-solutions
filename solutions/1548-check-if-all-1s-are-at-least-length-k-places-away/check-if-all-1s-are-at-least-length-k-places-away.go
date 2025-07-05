func kLengthApart(nums []int, k int) bool {
	start := false
	gap := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] == 1 {
			if start && gap < k {
				return false
			}
			start = true
			gap = 0
		} else if start && nums[i] == 0 {
			gap++
		}
	}
	return true
}