func minimumDifference(nums []int, k int) int {
	sort.Ints(nums)
	ans := math.MaxInt32
	for i, num := range nums[:len(nums)-k+1] {
		ans = min(ans, nums[i+k-1]-num)
	}
	return ans
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}