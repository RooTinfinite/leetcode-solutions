func separateDigits(nums []int) []int {
	res := []int{}
	for i := len(nums) - 1; i >= 0; i-- {
		x := nums[i]
		for x > 0 {
			res = append(res, x%10)
			x /= 10
		}
	}

	for i, j := 0, len(res)-1; i < j; i, j = i+1, j-1 {
		res[i], res[j] = res[j], res[i]
	}

	return res
}