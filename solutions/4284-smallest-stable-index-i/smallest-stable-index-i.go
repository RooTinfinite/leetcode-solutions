func firstStableIndex(nums []int, k int) int {
	n := len(nums)
	for i := 0; i < n; i++ {
		maxValue := nums[i]
		minValue := nums[i]
		for j := 0; j < i; j++ {
			if nums[j] > maxValue {
				maxValue = nums[j]
			}
		}
		for j := i + 1; j < n; j++ {
			if nums[j] < minValue {
				minValue = nums[j]
			}
		}
		if maxValue-minValue <= k {
			return i
		}
	}
	return -1
}