func maxNumberOfFamilies(n int, reservedSeats [][]int) int {
	left := 0b11110000
	middle := 0b11000011
	right := 0b00001111

	occupied := make(map[int]int)
	for _, seat := range reservedSeats {
		if seat[1] >= 2 && seat[1] <= 9 {
			occupied[seat[0]] |= (1 << (seat[1] - 2))
		}
	}

	ans := (n - len(occupied)) * 2
	for _, bitmask := range occupied {
		if (bitmask|left) == left ||
			(bitmask|middle) == middle ||
			(bitmask|right) == right {
			ans++
		}
	}
	return ans
}