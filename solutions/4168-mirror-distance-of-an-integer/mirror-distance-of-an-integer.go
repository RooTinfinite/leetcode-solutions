func reverse(n int) int {
	res := 0
	for n > 0 {
		res = res*10 + n%10
		n /= 10
	}
	return res
}

func mirrorDistance(n int) int {
	diff := n - reverse(n)
	if diff < 0 {
		return -diff
	}
	return diff
}