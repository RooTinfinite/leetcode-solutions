func minSwaps(nums []int) int {
	n := len(nums)
	digitSum := make([]int, n)
	for i, v := range nums {
		sum := 0
		for v > 0 {
			sum += v % 10
			v /= 10
		}
		digitSum[i] = sum
	}

	indices := make([]int, n)
	for i := 0; i < n; i++ {
		indices[i] = i
	}
	sort.Slice(indices, func(a, b int) bool {
		if digitSum[indices[a]] != digitSum[indices[b]] {
			return digitSum[indices[a]] < digitSum[indices[b]]
		}
		return nums[indices[a]] < nums[indices[b]]
	})

	targetPos := make([]int, n)
	for pos, idx := range indices {
		targetPos[idx] = pos
	}

	visited := make([]bool, n)
	cycles := 0
	for i := 0; i < n; i++ {
		if !visited[i] {
			cycles++
			j := i
			for !visited[j] {
				visited[j] = true
				j = targetPos[j]
			}
		}
	}

	return n - cycles
}