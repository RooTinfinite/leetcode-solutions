func maxLength(nums []int) int {
	res := 0
	gcd := func(a, b int64) int64 {
		for b != 0 {
			a, b = b, a%b
		}
		return a
	}

	for i := 0; i < len(nums); i++ {
		prodVal := int64(nums[i])
		gcdVal := int64(nums[i])
		lcmVal := int64(nums[i])
		for j := i + 1; j < len(nums); j++ {
			prodVal = prodVal * int64(nums[j])
			gcdVal = gcd(gcdVal, int64(nums[j]))
			lcmVal = lcmVal * int64(nums[j]) / gcd(lcmVal, int64(nums[j]))
			if prodVal > gcdVal*lcmVal {
				break
			}
			if prodVal == gcdVal*lcmVal {
				length := j - i + 1
				if length > res {
					res = length
				}
			}
		}
	}
	return res
}