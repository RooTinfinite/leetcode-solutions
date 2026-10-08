func removeOuterParentheses(s string) string {
	ans := []rune{}
	level := 0
	for _, c := range s {
		if c == ')' {
			level--
		}
		if level > 0 {
			ans = append(ans, c)
		}
		if c == '(' {
			level++
		}
	}
	return string(ans)
}