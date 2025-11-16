func grayCode(n int) []int {
    result := make([]int, 0)
    // there are 2 ^ n numbers in the Gray code sequence.
    sequenceLength := 1 << n
    for i := 0; i < sequenceLength; i++ {
        num := i ^ i>>1
        result = append(result, num)
    }
    return result
}