func longestSubsequenceRepeatedK(s string, k int) string {
	freq := make([]int, 26)
	for _, ch := range s {
		freq[ch-'a']++
	}

	var candidate []byte
	for i := 25; i >= 0; i-- {
		if freq[i] >= k {
			candidate = append(candidate, byte('a'+i))
		}
	}
	q := []string{}
	for _, ch := range candidate {
		q = append(q, string(ch))
	}
	ans := ""
	for len(q) > 0 {
		curr := q[0]
		q = q[1:]
		if len(curr) > len(ans) {
			ans = curr
		}
		// generate the next candidate string
		for _, c := range candidate {
			next := curr + string(c)
			if isKRepeated(s, next, k) {
				q = append(q, next)
			}
		}
	}

	return ans
}

func isKRepeated(s, pattern string, k int) bool {
	i, matched := 0, 0
	for _, c := range s {
		if c == rune(pattern[i]) {
			i++
			if i == len(pattern) {
				i = 0
				matched++
				if matched == k {
					return true
				}
			}
		}
	}
	return false
}