func smallestIndex(nums []int) int {
	for i, num := range nums {
		digitSum := 0

		for num > 0 {
			digitSum += num % 10
			num /= 10
		}

		if digitSum == i {
			return i
		}
	}

	return -1
}