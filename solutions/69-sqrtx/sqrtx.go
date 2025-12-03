func mySqrt(x int) int {
    if x < 2 {
        return x
    }
    x0 := float64(x)
    x1 := (x0 + float64(x)/x0) / 2.0
    for math.Abs(x0-x1) >= 1 {
        x0 = x1
        x1 = (x0 + float64(x)/x0) / 2.0
    }
    return int(x1)
}