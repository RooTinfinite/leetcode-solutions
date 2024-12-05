class Solution {
    func canChange(_ start: String, _ target: String) -> Bool {
        if start == target { return true }
        var waitL = 0, waitR = 0
        
        let startChars = Array(start)
        let targetChars = Array(target)
        
        for i in 0..<startChars.count {
            let curr = startChars[i]
            let goal = targetChars[i]
            
            if curr == "R" {
                if waitL > 0 { return false }
                waitR += 1
            }
            if goal == "L" {
                if waitR > 0 { return false }
                waitL += 1
            }
            if goal == "R" {
                if waitR == 0 { return false }
                waitR -= 1
            }
            if curr == "L" {
                if waitL == 0 { return false }
                waitL -= 1
            }
        }
        return waitL == 0 && waitR == 0
    }
}