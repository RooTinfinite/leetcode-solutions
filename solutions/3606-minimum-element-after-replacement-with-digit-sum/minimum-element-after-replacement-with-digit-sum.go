func minElement(nums []int) int {
	ans := 37
	for _, num := range nums {
		dig := 0
		n := num
		for n > 0 {
			dig += n % 10
			n /= 10
		}
		if dig < ans {
			ans = dig
		}
	}
	return ans
}
