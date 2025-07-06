func minInsertions(s string) int {
    openCounts := 0 // Tracks unmatched '('
    insertions := 0 // Tracks required insertions

    for i := 0; i < len(s); i++ {
        if s[i] == '(' {
            openCounts++
        } else if i+1 < len(s) && s[i+1] == ')' {
            if openCounts > 0 {
                openCounts--
            } else {
                insertions++
            }
            i++ // Skip the next ')'
        } else {
            if openCounts > 0 {
                openCounts--
                insertions++
            } else {
                insertions += 2
            }
        }
    }

    return insertions + 2*openCounts
}