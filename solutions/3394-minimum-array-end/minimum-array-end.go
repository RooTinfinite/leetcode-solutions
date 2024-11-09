func minEnd(n int, x int) int64 {
    result := int64(x)
    remaining := int64(n - 1)
    position := int64(1)
    
    for remaining != 0 {
        if (int64(x) & position) == 0 {
            result |= (remaining & 1) * position
            remaining >>= 1
        }
        position <<= 1
    }
    
    return result
}