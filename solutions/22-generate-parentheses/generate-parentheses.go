func generateParenthesis(n int) []string {
    if n == 0 {
        return []string{""}
    }
    var result []string
    for leftCount := 0; leftCount < n; leftCount++ {
        leftStrings := generateParenthesis(leftCount)
        rightStrings := generateParenthesis(n - 1 - leftCount)
        for _, leftString := range leftStrings {
            for _, rightString := range rightStrings {
                result = append(result, "("+leftString+")"+rightString)
            }
        }
    }
    return result
}