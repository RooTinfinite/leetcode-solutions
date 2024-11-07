func calcScale(c byte, a1 byte, a2 byte) int {
    if c == a1 || c == a2 {
        return -1
    }
    return 1
}

func romanToInt(s string) int {
    result := 0
    
    for n := 0; n < len(s); n++ {
        var nextChar byte
        if n+1 < len(s) {
            nextChar = s[n+1]
        }
        
        switch s[n] {
        case 'M':
            result += 1000
        case 'D':
            result += 500
        case 'C':
            result += 100 * calcScale(nextChar, 'M', 'D')
        case 'L':
            result += 50
        case 'X':
            result += 10 * calcScale(nextChar, 'C', 'L')
        case 'V':
            result += 5
        case 'I':
            result += 1 * calcScale(nextChar, 'X', 'V')
        }
    }
    return result
}