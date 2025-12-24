func minimumBoxes(apple []int, capacity []int) int {
	sum := 0
	for _, a := range apple {
		sum += a
	}

	sort.Sort(sort.Reverse(sort.IntSlice(capacity)))
	need := 0
	for sum > 0 {
		sum -= capacity[need]
		need++
	}

	return need
}