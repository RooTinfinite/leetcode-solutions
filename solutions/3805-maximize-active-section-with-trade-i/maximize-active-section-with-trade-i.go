func maxActiveSectionsAfterTrade(s string) int {
	n := len(s)
	cnt1 := 0
	for _, c := range s {
		if c == '1' {
			cnt1++
		}
	}

	i := 0
	bestGain := 0
	prev := -1 << 31
	cur := 0

	for i < n {
		start := i
		for i < n && s[i] == s[start] {
			i++
		}
		if s[start] == '0' {
			cur = i - start
			if prev != -1<<31 {
				bestGain = max(bestGain, prev+cur)
			}
			prev = cur
		}
	}

	return cnt1 + bestGain
}