func decrypt(code []int, k int) []int {
    N := len(code)
    res := make([]int, N)
    
    if k == 0 {
        return res
    }
    
    l := 0
    curSum := 0
    for r := 0; r < N + abs(k); r++ {
        curSum += code[r % N]
        
        if r - l + 1 > abs(k) {
            curSum -= code[l % N]
            l = (l + 1) % N
        }
        
        if r - l + 1 == abs(k) {
            if k > 0 {
                res[(l - 1 + N) % N] = curSum
            } else {
                res[(r + 1) % N] = curSum
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