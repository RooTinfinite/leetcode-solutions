func minWindow(s string, t string) string {
    if len(s) == 0 || len(t) == 0 {
        return ""
    }
    dictT := make(map[rune]int)
    for _, char := range t {
        dictT[char]++
    }
    required := len(dictT)
    filteredS := []struct {
        index   int
        element rune
    }{}
    for i, char := range s {
        if _, ok := dictT[char]; ok {
            filteredS = append(filteredS, struct {
                index   int
                element rune
            }{index: i, element: char})
        }
    }
    l, r, formed := 0, 0, 0
    windowCounts := make(map[rune]int)
    ans := []int{-1, 0, 0}
    for r < len(filteredS) {
        char := filteredS[r].element
        windowCounts[char]++
        if count, ok := dictT[char]; ok && windowCounts[char] == count {
            formed++
        }
        for l <= r && formed == required {
            char := filteredS[l].element
            end := filteredS[r].index
            start := filteredS[l].index
            if ans[0] == -1 || end-start+1 < ans[0] {
                ans[0] = end - start + 1
                ans[1] = start
                ans[2] = end
            }
            windowCounts[char]--
            if count, ok := dictT[char]; ok && windowCounts[char] < count {
                formed--
            }
            l++
        }
        r++
    }
    if ans[0] == -1 {
        return ""
    } else {
        return s[ans[1] : ans[2]+1]
    }
}