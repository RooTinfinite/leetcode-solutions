func maxValue(nums []int) []int {
	n := len(nums)
	ans := make([]int, n)

	type Item struct {
		value int
		left  int
		right int
	}

	stack := make([]Item, 0)
	for i := 0; i < n; i++ {
		curr := Item{nums[i], i, i}

		for len(stack) > 0 && stack[len(stack)-1].value > nums[i] {
			top := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			if top.value > curr.value {
				curr.value = top.value
			}
			curr.left = top.left
		}

		stack = append(stack, curr)
	}

	for i := 0; i < len(stack); i++ {
		for j := stack[i].left; j <= stack[i].right; j++ {
			ans[j] = stack[i].value
		}
	}

	return ans
}