func canReach(arr []int, start int) bool {
	n := len(arr)

	visited := make([]bool, n)
	q := []int{start}

	for len(q) > 0 {
		i := q[0]
		q = q[1:]

		if i < 0 || i >= n || visited[i] {
			continue
		}

		if arr[i] == 0 {
			return true
		}

		visited[i] = true

		q = append(q, i+arr[i])
		q = append(q, i-arr[i])
	}

	return false
}