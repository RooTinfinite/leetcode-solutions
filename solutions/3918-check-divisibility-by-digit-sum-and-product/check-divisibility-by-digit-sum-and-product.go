func checkDivisibility(n int) bool {
	digitSum := 0
	digitProduct := 1
	original := n

	for n > 0 {
		digit := n % 10
		n /= 10

		digitSum += digit
		digitProduct *= digit
	}

	return original%(digitSum+digitProduct) == 0
}