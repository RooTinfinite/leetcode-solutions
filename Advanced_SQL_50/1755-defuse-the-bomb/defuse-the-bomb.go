func decrypt(circ []int, k int) []int {
    n := len(circ)
    result := make([]int, n)
    
    if k == 0 {
        return result
    }
    
    wSum := 0
    var start, end int
    
    if k > 0 {
        start = 1
        end = k
    } else {
        start = n + k
        end = n - 1
    }
    
    for i := start; i <= end; i++ {
        wSum += circ[i%n]
    }
    
    for i := 0; i < n; i++ {
        result[i] = wSum
        wSum -= circ[(start+i)%n]
        wSum += circ[(end+i+1)%n]
    }
    
    return result
}