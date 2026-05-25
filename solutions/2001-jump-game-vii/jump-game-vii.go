func canReach(s string, minJump int, maxJump int) bool {
	n := len(s)
	f := make([]int, n)
	pre := make([]int, n)
	f[0] = 1
	// since we start dynamic programming from i=minJump, we need to precompute
	// the prefix sums for the part [0, minJump)
	for i := 0; i < minJump; i++ {
		pre[i] = 1
	}
	for i := minJump; i < n; i++ {
		left := i - maxJump
		right := i - minJump
		if s[i] == '0' {
			total := pre[right]
			if left > 0 {
				total -= pre[left-1]
			}
			if total != 0 {
				f[i] = 1
			} else {
				f[i] = 0
			}
		}
		pre[i] = pre[i-1] + f[i]
	}
	return f[n-1] == 1
}