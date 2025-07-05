func maxPower(s string) int {
    if len(s) < 2 {
        return len(s)
    }
    s += " "

    mx := 1
    c := 1

    for i := 0; i < len(s) - 1; i++ {
        if s[i] == s[i + 1] {
            c++
        } else {
            mx = max(mx, c)
            c = 1
        }
    }    

    return mx
}