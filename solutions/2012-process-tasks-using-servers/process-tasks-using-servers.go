type Pair struct{ first, second int }

func assignTasks(servers []int, tasks []int) []int {
	// Busy servers, ordered by time
	busy := &MinHeap{less: func(a, b Pair) bool { return a.first < b.first }}
	heap.Init(busy)

	// Idle servers, ordered by weight and index
	idle := &MinHeap{less: func(a, b Pair) bool {
		if a.first != b.first {
			return a.first < b.first
		}
		return a.second < b.second
	}}
	heap.Init(idle)

	for i, w := range servers {
		heap.Push(idle, Pair{w, i})
	}

	ts := 0
	ans := make([]int, len(tasks))

	// Move servers with t<=ts from priority queue busy to priority queue idle one by one
	release := func() {
		for busy.Len() > 0 && busy.Top().first <= ts {
			s := heap.Pop(busy).(Pair)
			heap.Push(idle, Pair{servers[s.second], s.second})
		}
	}

	for i, task := range tasks {
		ts = max(ts, i)
		release()
		if idle.Len() == 0 {
			ts = busy.Top().first
			release()
		}

		s := heap.Pop(idle).(Pair)
		ans[i] = s.second
		heap.Push(busy, Pair{ts + task, s.second})
	}

	return ans
}

type MinHeap struct {
	data []Pair
	less func(a, b Pair) bool
}

func (h *MinHeap) Len() int           { return len(h.data) }
func (h *MinHeap) Less(i, j int) bool { return h.less(h.data[i], h.data[j]) }
func (h *MinHeap) Swap(i, j int)      { h.data[i], h.data[j] = h.data[j], h.data[i] }
func (h *MinHeap) Push(x any)         { h.data = append(h.data, x.(Pair)) }
func (h *MinHeap) Pop() any {
	old := h.data
	n := len(old)
	x := old[n-1]
	h.data = old[:n-1]
	return x
}
func (h *MinHeap) Top() Pair { return h.data[0] }

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}