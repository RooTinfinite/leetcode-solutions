func minMaxDifference(num int) int {
	s := strconv.Itoa(num)
	t := s
	pos := 0
	for pos < len(s) && s[pos] == '9' {
		pos++
	}
	if pos < len(s) {
		s = strings.ReplaceAll(s, string(s[pos]), "9")
	}
	t = strings.ReplaceAll(t, string(t[0]), "0")
	max, _ := strconv.Atoi(s)
	min, _ := strconv.Atoi(t)
	return max - min
}