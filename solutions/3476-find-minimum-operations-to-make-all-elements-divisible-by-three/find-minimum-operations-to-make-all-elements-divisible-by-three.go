func minimumOperations(nums []int) int {
	sum := 0
	for _, x := range nums {
		remainder := x % 3
		sum += min(remainder, 3-remainder)
	}
	return sum
}