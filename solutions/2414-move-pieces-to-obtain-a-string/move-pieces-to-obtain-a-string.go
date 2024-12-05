func canChange(start string, target string) bool {
    if start == target {
        return true
    }
    waitL, waitR := 0, 0
    
    for i := 0; i < len(start); i++ {
        curr := start[i]
        goal := target[i]
        
        if curr == 'R' {
            if waitL > 0 {
                return false
            }
            waitR++
        }
        if goal == 'L' {
            if waitR > 0 {
                return false
            }
            waitL++
        }
        if goal == 'R' {
            if waitR == 0 {
                return false
            }
            waitR--
        }
        if curr == 'L' {
            if waitL == 0 {
                return false
            }
            waitL--
        }
    }
    return waitL == 0 && waitR == 0
}