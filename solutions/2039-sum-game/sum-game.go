func sumGame(num string) bool {
	n := len(num)

	get := func(s string) (int, int) {
		nn, qq := 0, 0
		for _, ch := range s {
			if ch == '?' {
				qq++
			} else {
				nn += int(ch - '0')
			}
		}
		return nn, qq
	}

	n0, q0 := get(num[:n/2])
	n1, q1 := get(num[n/2:])

	return ((q0+q1)%2 == 1) || (n0-n1 != (q1-q0)*9/2)
}