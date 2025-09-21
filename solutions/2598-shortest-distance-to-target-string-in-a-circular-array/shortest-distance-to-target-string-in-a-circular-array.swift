class Solution {
    func closestTarget(_ W: [String], _ T: String, _ s: Int) -> Int {
        var a = Int.max, n = W.count
        for i in 0..<n {
            if W[i] == T {
                let d = abs(i - s)
                a = min(a, min(d, n - d))
            }
        }
        return a == Int.max ? -1 : a
    }
}