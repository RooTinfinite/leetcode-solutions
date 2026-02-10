func longestBalanced(nums []int) int {
	maxLen := 0

	for i := 0; i < len(nums); i++ {
		odd := make(map[int]int)
		even := make(map[int]int)

		for j := i; j < len(nums); j++ {
			if nums[j]&1 == 1 {
				odd[nums[j]]++
			} else {
				even[nums[j]]++
			}

			if len(odd) == len(even) {
				if j-i+1 > maxLen {
					maxLen = j - i + 1
				}
			}
		}
	}

	return maxLen
}