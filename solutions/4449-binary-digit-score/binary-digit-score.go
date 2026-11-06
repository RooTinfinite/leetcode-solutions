func calculateScore(a int, b int) int {
    c, d := 0, 0
    for a > 0 {
        c += a & 1
        a >>= 1
    }
    for b > 0 {
        d += b & 1
        b >>= 1
    }
    if c >= d {
        return c * d
    }
    return d / c
}