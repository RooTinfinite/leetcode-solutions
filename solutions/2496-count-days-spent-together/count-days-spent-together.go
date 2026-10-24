func countDaysTogether(arriveAlice string, leaveAlice string, arriveBob string, leaveBob string) int {
	datesOfMonths := []int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	prefixSum := make([]int, 1)
	for _, date := range datesOfMonths {
		prefixSum = append(prefixSum, prefixSum[len(prefixSum)-1]+date)
	}

	arriveAliceDay := calculateDayOfYear(arriveAlice, prefixSum)
	leaveAliceDay := calculateDayOfYear(leaveAlice, prefixSum)
	arriveBobDay := calculateDayOfYear(arriveBob, prefixSum)
	leaveBobDay := calculateDayOfYear(leaveBob, prefixSum)

	return max(0, min(leaveAliceDay, leaveBobDay)-max(arriveAliceDay, arriveBobDay)+1)
}

func calculateDayOfYear(day string, prefixSum []int) int {
	month, _ := strconv.Atoi(day[:2])
	date, _ := strconv.Atoi(day[3:])
	return prefixSum[month-1] + date
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}