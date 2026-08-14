func maximumLengthSubstring(s string) int {
	n := len(s)
	res := 0
	for left := 0; left < n; left++ {
		count := make([]int, 26)
		for right := left; right < n; right++ {
			ch := s[right] - 'a'
			count[ch]++
			if count[ch] > 2 {
				break
			}
			length := right - left + 1
			if length > res {
				res = length
			}
		}
	}
	return res
}