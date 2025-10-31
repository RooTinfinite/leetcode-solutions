func getSneakyNumbers(nums []int) []int {
	res := []int{}
	count := make(map[int]int)
	for _, x := range nums {
		count[x]++
		if count[x] == 2 {
			res = append(res, x)
		}
	}
	return res
}