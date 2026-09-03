func uniformArray(nums1 []int) bool {
	mn := nums1[0]
	hasOdd := false
	for _, v := range nums1 {
		if v < mn {
			mn = v
		}
		if v%2 == 1 {
			hasOdd = true
		}
	}
	if mn%2 == 1 {
		return true
	}
	return !hasOdd
}