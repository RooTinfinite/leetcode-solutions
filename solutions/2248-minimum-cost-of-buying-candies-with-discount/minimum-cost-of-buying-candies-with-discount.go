func minimumCost(cost []int) int {
	sort.Sort(sort.Reverse(sort.IntSlice(cost)))
	res := 0
	n := len(cost)
	for i := 0; i < n; i++ {
		if i%3 != 2 {
			res += cost[i]
		}
	}
	return res
}