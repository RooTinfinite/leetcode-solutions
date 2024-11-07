func romanToInt(s string) int {
    roman := map[byte]int{
        'I': 1, 'V': 5, 'X': 10,
        'L': 50, 'C': 100, 'D': 500, 'M': 1000,
    }
    
    n := len(s)
    result := roman[s[n-1]]
    
    for i := n-2; i >= 0; i-- {
        if roman[s[i]] < roman[s[i+1]] {
            result -= roman[s[i]]
        } else {
            result += roman[s[i]]
        }
    }
    
    return result
}