func findSafeWalk(grid [][]int, health int) bool {
	m, n := len(grid), len(grid[0])
	dirs := [][2]int{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}

	dis := make([][]int, m)
	for i := range dis {
		dis[i] = make([]int, n)
		for j := range dis[i] {
			dis[i][j] = math.MaxInt32
		}
	}

	q := list.New()
	q.PushFront([2]int{0, 0})
	dis[0][0] = grid[0][0]

	for q.Len() > 0 {
		cur := q.Remove(q.Front()).([2]int)
		cx, cy := cur[0], cur[1]
		// the first time it leaves the queue, the shortest distance is
		// guaranteed
		if cx == m-1 && cy == n-1 {
			return true
		}

		for _, dir := range dirs {
			nx, ny := cx+dir[0], cy+dir[1]
			if nx < 0 || ny < 0 || nx >= m || ny >= n {
				continue
			}

			cost := dis[cx][cy] + grid[nx][ny]
			// pruning: the new distance does not meet health requirements
			if cost >= health {
				continue
			}

			if cost < dis[nx][ny] {
				dis[nx][ny] = cost
				if grid[nx][ny] == 0 {
					q.PushFront([2]int{nx, ny})
				} else {
					q.PushBack([2]int{nx, ny})
				}
			}
		}
	}
	return false
}