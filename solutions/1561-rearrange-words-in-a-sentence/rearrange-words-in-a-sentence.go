func arrangeWords(text string) string {
    words := strings.Fields(strings.ToLower(text))
    sort.SliceStable(words, func(i, j int) bool {
        return len(words[i]) < len(words[j])
    })
    returnVal := strings.Join(words, " ")
    return strings.ToUpper(string(returnVal[0])) + returnVal[1:]
}