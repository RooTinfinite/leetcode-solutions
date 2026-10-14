func maxSumOfSquares(num int, sum int) string {
	if sum > 9*num {
		return ""
	}
	r := sum % 9
	ans := make([]byte, 0, num)
	for i := 0; i < sum/9; i++ {
		ans = append(ans, '9')
	}
	if r > 0 {
		ans = append(ans, byte('0'+r))
	}
	zeros := num - len(ans)
	for i := 0; i < zeros; i++ {
		ans = append(ans, '0')
	}
	return string(ans)
}