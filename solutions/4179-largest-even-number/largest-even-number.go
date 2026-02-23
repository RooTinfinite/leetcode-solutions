func largestEven(s string) string {
    ind := -1

    for i := len(s) - 1; i >= 0; i-- {
        if s[i] == '2' {
            ind = i
            break
        }
    }

    return s[:ind+1]
}