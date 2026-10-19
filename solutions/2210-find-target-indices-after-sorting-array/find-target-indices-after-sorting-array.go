func targetIndices(nums []int, target int) []int {
	cnt1 := 0 // Number of elements less than target
	cnt2 := 0 // Number of elements equal to target

	for _, num := range nums {
		if num < target {
			cnt1++
		} else if num == target {
			cnt2++
		}
	}

	res := make([]int, cnt2)
	for i := 0; i < cnt2; i++ {
		res[i] = cnt1 + i
	}
	return res
}