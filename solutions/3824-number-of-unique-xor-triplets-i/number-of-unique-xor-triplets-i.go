func uniqueXorTriplets(nums []int) int {
	n := len(nums)
	if n <= 2 {
		return n
	}
	ans := 1
	for ans <= n {
		ans <<= 1
	}
	return ans
}