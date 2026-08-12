func isValid(s string) bool {
    mappings := map[rune]rune{')': '(', '}': '{', ']': '['}
    stack := make([]rune, 0)
    for _, c := range s {
        if val, ok := mappings[c]; ok {
            var topElement rune = '#'
            if len(stack) != 0 {
                topElement, stack = stack[len(stack)-1], stack[:len(stack)-1]
            }
            if topElement != val {
                return false
            }
        } else {
            stack = append(stack, c)
        }
    }
    return len(stack) == 0
}