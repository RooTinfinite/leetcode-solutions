func countOperations(num1 int, num2 int) int {
	res := 0 // total number of subtraction operations
	for num1 != 0 && num2 != 0 {
		// each step of the Euclidean algorithm
		res += num1 / num2
		num1 %= num2
		// swap two numbers
		num1, num2 = num2, num1
	}
	return res
}