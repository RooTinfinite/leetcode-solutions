func reverseDegree(s string) int {
	ans := 0
	for i := 1; i <= len(s); i++ {
		ans += (26 - int(s[i-1]-'a')) * i
	}
	return ans
}