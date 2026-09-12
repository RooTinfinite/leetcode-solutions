func maximumWeight(intervals [][]int) []int {
	n := len(intervals)
	type Interval struct {
		l, r, weight, idx int
	}
	arr := make([]Interval, n)
	for i := 0; i < n; i++ {
		arr[i] = Interval{intervals[i][0], intervals[i][1], intervals[i][2], i}
	}
	// Sort by right endpoint.
	sort.Slice(arr, func(i, j int) bool {
		return arr[i].r < arr[j].r
	})

	dp := make([][]int64, n+1)
	indices := make([][][]int, n+1)
	for i := 0; i <= n; i++ {
		dp[i] = make([]int64, 5)
		indices[i] = make([][]int, 5)
		for j := 0; j < 5; j++ {
			indices[i][j] = []int{}
		}
	}

	for i := 0; i < n; i++ {
		l, weight, idx := arr[i].l, arr[i].weight, arr[i].idx
		// Use binary search to find intervals whose right endpoints are smaller
		// than l.
		k := sort.Search(i, func(pos int) bool {
			return arr[pos].r >= l
		})

		for j := 1; j < 5; j++ {
			s1 := dp[i][j]
			s2 := dp[k][j-1] + int64(weight)
			if s1 > s2 {
				dp[i+1][j] = dp[i][j]
				indices[i+1][j] = append([]int{}, indices[i][j]...)
				continue
			}

			newIndex := append([]int{}, indices[k][j-1]...)
			newIndex = append(newIndex, idx)
			sort.Ints(newIndex)
			if s1 == s2 && compareSlices(indices[i][j], newIndex) < 0 {
				newIndex = append([]int{}, indices[i][j]...)
			}
			dp[i+1][j] = s2
			indices[i+1][j] = newIndex
		}
	}

	return indices[n][4]
}

func compareSlices(a, b []int) int {
	minLen := len(a)
	if len(b) < minLen {
		minLen = len(b)
	}
	for i := 0; i < minLen; i++ {
		if a[i] != b[i] {
			return a[i] - b[i]
		}
	}
	return len(a) - len(b)
}