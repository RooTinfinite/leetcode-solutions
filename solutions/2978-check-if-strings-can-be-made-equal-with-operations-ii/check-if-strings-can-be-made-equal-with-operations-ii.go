func checkStrings(s1 string, s2 string) bool {
	if len(s1) != len(s2) {
		return false
	}

	var counts [256]int

	for i := 0; i < len(s1); i++ {
		offset := (i & 1) << 7
		counts[offset+int(s1[i])]++
		counts[offset+int(s2[i])]--
	}

	for _, count := range counts {
		if count != 0 {
			return false
		}
	}

	return true
}