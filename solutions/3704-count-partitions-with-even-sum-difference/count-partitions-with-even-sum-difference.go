func countPartitions(nums []int) int {
	totalSum := 0
	for _, x := range nums {
		totalSum += x
	}
	if totalSum%2 == 0 {
		return len(nums) - 1
	}
	return 0
}