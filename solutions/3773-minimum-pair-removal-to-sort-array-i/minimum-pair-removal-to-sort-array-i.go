func minimumPairRemoval(nums []int) int {
	count := 0

	for len(nums) > 1 {
		isAscending := true
		minSum := 1<<31 - 1
		targetIndex := -1

		for i := 0; i < len(nums)-1; i++ {
			sum := nums[i] + nums[i+1]
			if nums[i] > nums[i+1] {
				isAscending = false
			}
			if sum < minSum {
				minSum = sum
				targetIndex = i
			}
		}

		if isAscending {
			break
		}
		count++
		nums[targetIndex] = minSum
		nums = append(nums[:targetIndex+1], nums[targetIndex+2:]...)
	}

	return count
}