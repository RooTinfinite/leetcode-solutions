func firstStableIndex(nums []int, k int) int {
	n := len(nums)
	minValue := make([]int, n)
	minValue[n-1] = nums[n-1]
	for i := n - 2; i >= 0; i-- {
		if minValue[i+1] < nums[i] {
			minValue[i] = minValue[i+1]
		} else {
			minValue[i] = nums[i]
		}
	}

	maxValue := 0
	for i := 0; i < n; i++ {
		if nums[i] > maxValue {
			maxValue = nums[i]
		}
		if maxValue-minValue[i] <= k {
			return i
		}
	}
	return -1
}