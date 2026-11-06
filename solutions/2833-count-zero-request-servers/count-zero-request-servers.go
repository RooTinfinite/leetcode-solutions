func countServers(n int, logs [][]int, x int, queries []int) []int {
	sort.Slice(logs, func(a, b int) bool {
		return logs[a][1] < logs[b][1]
	})

	m := len(queries)
	ids := make([]int, m)
	for i := range ids {
		ids[i] = i
	}
	sort.Slice(ids, func(a, b int) bool {
		return queries[ids[a]] < queries[ids[b]]
	})

	ans := make([]int, m)
	cnt := make([]int, n+1)
	left, right, active := 0, 0, 0

	for _, i := range ids {
		q := queries[i]
		for right < len(logs) && logs[right][1] <= q {
			id := logs[right][0]
			right++
			cnt[id]++
			if cnt[id] == 1 {
				active++
			}
		}
		for left < right && logs[left][1] < q-x {
			id := logs[left][0]
			left++
			cnt[id]--
			if cnt[id] == 0 {
				active--
			}
		}
		ans[i] = n - active
	}
	return ans
}