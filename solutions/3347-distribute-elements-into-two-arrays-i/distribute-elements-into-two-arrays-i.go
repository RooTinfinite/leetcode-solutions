func resultArray(nums []int) []int {
	n := len(nums)
	arr := make([]int, n)
	arr[0] = nums[0]
	arr[n-1] = nums[1]
	idx, revIdx := 0, n-1
	for i := 2; i < n; i++ {
		if arr[idx] > arr[revIdx] {
			idx++
			arr[idx] = nums[i]
		} else {
			revIdx--
			arr[revIdx] = nums[i]
		}
	}
	for l, r := revIdx, n-1; l < r; l, r = l+1, r-1 {
		arr[l], arr[r] = arr[r], arr[l]
	}
	return arr
}