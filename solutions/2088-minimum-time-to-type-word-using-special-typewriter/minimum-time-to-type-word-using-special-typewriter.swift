class Solution {
    func minTimeToType(_ word: String) -> Int {
        var ans = word.count
        var cur = 1
        for ch in word {
            let pos = Int(ch.asciiValue!) - 96
            let diff = abs(pos - cur)
            ans += min(diff, 26 - diff)
            cur = pos
        }
        return ans
    }
}