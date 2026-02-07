func minimumDeletions(s string) int {
    bCount := 0
    res := 0
    n := len(s)
    
    for i := 0; i < n; i++ {
        if s[i] == 'b' {
            bCount++
        } else {
            if res + 1 < bCount {
                res++
            } else {
                res = bCount
            }
        }
    }
    
    return res
}