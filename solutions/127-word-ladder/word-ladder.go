func ladderLength(beginWord string, endWord string, wordList []string) int {
    L := len(beginWord)
    allComboDict := make(map[string][]string)
    for _, word := range wordList {
        for i := 0; i < L; i++ {
            newWord := word[:i] + "*" + word[i+1:L]
            allComboDict[newWord] = append(allComboDict[newWord], word)
        }
    }
    Q := make([][]interface{}, 0, len(wordList))
    Q = append(Q, []interface{}{beginWord, 1})
    visited := make(map[string]bool)
    visited[beginWord] = true
    for len(Q) > 0 {
        node := Q[0]
        Q = Q[1:]
        word := node[0].(string)
        level := node[1].(int)
        for i := 0; i < L; i++ {
            newWord := word[:i] + "*" + word[i+1:L]
            for _, adjacentWord := range allComboDict[newWord] {
                if adjacentWord == endWord {
                    return level + 1
                }
                if !visited[adjacentWord] {
                    visited[adjacentWord] = true
                    Q = append(Q, []interface{}{adjacentWord, level + 1})
                }
            }
        }
    }
    return 0
}