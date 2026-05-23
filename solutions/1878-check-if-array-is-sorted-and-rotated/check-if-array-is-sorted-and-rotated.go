func check(nums []int) bool {
	n := len(nums)
	breaks := 0

	for i := 0; i < n; i++ {
		if nums[i] > nums[(i+1)%n] {
			breaks++
		}
	}

	return breaks <= 1
}