func minimumEffort(tasks [][]int) int {
	sort.Slice(tasks, func(i, j int) bool {
		return tasks[i][1]-tasks[i][0] > tasks[j][1]-tasks[j][0]
	})
	ans := 0
	remain := 0
	for _, task := range tasks {
		if remain > task[1] {
			// 不需要增加能量
		} else {
			ans += task[1] - remain
		}
		if task[1]-task[0] > remain-task[0] {
			remain = task[1] - task[0]
		} else {
			remain = remain - task[0]
		}
	}
	return ans
}