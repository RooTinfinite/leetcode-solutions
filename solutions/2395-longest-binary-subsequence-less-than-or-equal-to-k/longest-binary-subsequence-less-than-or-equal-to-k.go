func longestSubsequence(s string, k int) int {
	sm := 0
	cnt := 0
	bits := bits.Len(uint(k))
	for i := 0; i < len(s); i++ {
		ch := s[len(s)-1-i]
		if ch == '1' {
			if i < bits && sm+(1<<i) <= k {
				sm += 1 << i
				cnt++
			}
		} else {
			cnt++
		}
	}
	return cnt
}