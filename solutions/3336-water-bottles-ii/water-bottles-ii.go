func maxBottlesDrunk(numBottles int, numExchange int) int {
	a := 1
	b := 2*numExchange - 3
	c := -2 * numBottles
	delta := float64(b*b - 4*a*c)
	t := int(math.Ceil((-float64(b) + math.Sqrt(delta)) / (2.0 * float64(a))))
	return numBottles + t - 1
}