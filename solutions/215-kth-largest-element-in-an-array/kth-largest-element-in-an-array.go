import "container/heap"

func findKthLargest(nums []int, k int) int {
    h := IntHeap(nums[:k])
    heap.Init(&h)
    
    for _, num := range nums[k:] {
        if num > h[0] {
            heap.Pop(&h)
            heap.Push(&h, num)
        }
    }
    
    return h[0]
}

type IntHeap []int

func (h IntHeap) Len() int { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int) { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
    *h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[0 : n-1]
    return x
}