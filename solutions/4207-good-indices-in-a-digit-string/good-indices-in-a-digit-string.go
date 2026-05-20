func goodIndices(s string) []int {
    res := []int{}
    i, il := 1, 1
    for i <= len(s) {
        v, _ := strconv.Atoi(s[i-il:i])
        if v == i-1 {
            res = append(res, i-1)
        }
        i ++
        il = IntLen(i-1)
    }
    return res
}


func IntLen(n int) int {
    if n < 100000 {
        if n < 100 {
            if n < 10 {
                return 1
            }
            return 2
        } else {
            if n < 1000 {
                return 3
            } else if n < 10000 {
                return 4
            }
            return 5
        }
    }
    return 6
}