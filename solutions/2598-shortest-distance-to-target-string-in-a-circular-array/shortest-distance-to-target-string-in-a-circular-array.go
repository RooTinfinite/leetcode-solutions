package main

func closestTarget(W []string, T string, s int) int {
    a, n := int(^uint(0)>>1), len(W)
    for i := 0; i < n; i++ {
        if W[i] == T {
            d := i - s
            if d < 0 {
                d = -d
            }
            if d > n-d {
                d = n - d
            }
            if d < a {
                a = d
            }
        }
    }
    if a == int(^uint(0)>>1) {
        return -1
    }
    return a
}