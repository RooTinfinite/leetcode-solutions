func longestValidParentheses(s string) int {
    left, right, maxlength := 0, 0, 0
    for i := 0; i < len(s); i++ {
        if s[i] == '(' {
            left++
        } else {
            right++
        }
        if left == right {
            maxlength = max(maxlength, 2*right)
        } else if right > left {
            left, right = 0, 0
        }
    }
    left, right = 0, 0
    for i := len(s) - 1; i >= 0; i-- {
        if s[i] == '(' {
            left++
        } else {
            right++
        }
        if left == right {
            maxlength = max(maxlength, 2*left)
        } else if left > right {
            left, right = 0, 0
        }
    }
    return maxlength
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}