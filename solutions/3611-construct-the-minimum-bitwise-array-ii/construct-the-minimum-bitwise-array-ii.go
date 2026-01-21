func minBitwiseArray(nums []int) []int {
	for i, x := range nums {
		res := -1
		d := 1
		for (x & d) != 0 {
			res = x - d
			d <<= 1
		}
		nums[i] = res
	}
	return nums
}