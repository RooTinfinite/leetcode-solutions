import "github.com/emirpasic/gods/trees/redblacktree"

type multiSet struct {
	tree *redblacktree.Tree
	size int
	sum  int64
}

func (s *multiSet) add(value int) {
	count := 0
	if v, ok := s.tree.Get(value); ok {
		count = v.(int)
	}
	s.tree.Put(value, count+1)
	s.size++
	s.sum += int64(value)
}

func (s *multiSet) remove(value int) {
	v, _ := s.tree.Get(value)
	count := v.(int)
	if count == 1 {
		s.tree.Remove(value)
	} else {
		s.tree.Put(value, count-1)
	}
	s.size--
	s.sum -= int64(value)
}

func (s *multiSet) min() int { return s.tree.Left().Key.(int) }
func (s *multiSet) max() int { return s.tree.Right().Key.(int) }

func getCosts(nums []int, x int) []int64 {
	n := len(nums)
	ops := make([]int64, n)
	left := &multiSet{tree: redblacktree.NewWithIntComparator()}
	right := &multiSet{tree: redblacktree.NewWithIntComparator()}

	for i, value := range nums {
		if left.size == 0 || value <= left.max() {
			left.add(value)
		} else {
			right.add(value)
		}
		if i >= x {
			value = nums[i-x]
			if _, ok := left.tree.Get(value); ok {
				left.remove(value)
			} else {
				right.remove(value)
			}
		}
		if left.size > right.size+1 {
			value = left.max()
			left.remove(value)
			right.add(value)
		} else if left.size < right.size {
			value = right.min()
			right.remove(value)
			left.add(value)
		}
		if i >= x-1 {
			mid := int64(left.max())
			ops[i] = mid*int64(left.size) - left.sum + right.sum - mid*int64(right.size)
		}
	}
	return ops
}

func minOperations(nums []int, x int, k int) int64 {
	n := len(nums)
	ops := getCosts(nums, x)
	pre := make([]int64, n+1)
	cur := make([]int64, n+1)

	for j := 1; j <= k; j++ {
		for i := range cur {
			cur[i] = 1<<63 - 1
		}
		for i := j * x; i <= n; i++ {
			cur[i] = min(cur[i-1], pre[i-x]+ops[i-1])
		}
		pre, cur = cur, pre
	}
	return pre[n]
}