func dietPlanPerformance(calories []int, k int, lower int, upper int) int {
	sum, score := 0, 0
	for i := 0; i < k; i++ {
		sum += calories[i]
	}
	for i := k; ; i++ {
		if sum < lower {
			score--
		} else if sum > upper {
			score++
		}
		if i == len(calories) {
			break
		}
		sum += calories[i] - calories[i-k]
	}
	return score
}