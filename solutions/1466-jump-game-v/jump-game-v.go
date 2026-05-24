func maxJumps(arr []int, d int) int {
	n := len(arr)
	f := make([]int, n)
	for i := range f {
		f[i] = -1
	}

	var dfs func(int)
	dfs = func(id int) {
		if f[id] != -1 {
			return
		}
		f[id] = 1
		for i := id - 1; i >= 0 && id-i <= d && arr[id] > arr[i]; i-- {
			dfs(i)
			if f[i]+1 > f[id] {
				f[id] = f[i] + 1
			}
		}
		for i := id + 1; i < n && i-id <= d && arr[id] > arr[i]; i++ {
			dfs(i)
			if f[i]+1 > f[id] {
				f[id] = f[i] + 1
			}
		}
	}

	for i := 0; i < n; i++ {
		dfs(i)
	}

	ans := 0
	for _, val := range f {
		if val > ans {
			ans = val
		}
	}
	return ans
}