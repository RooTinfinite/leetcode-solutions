func decrypt(code []int, k int) []int {
    N := len(code)
    res := make([]int, N)
    
    for i := 0; i < N; i++ {
        if k > 0 {
            for j := i + 1; j < i + 1 + k; j++ {
                res[i] += code[j % N]
            }
        } else if k < 0 {
            for j := i - 1; j > i - 1 - abs(k); j-- {
                res[i] += code[((j % N) + N) % N]
            }
        }
    }
    
    return res
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}