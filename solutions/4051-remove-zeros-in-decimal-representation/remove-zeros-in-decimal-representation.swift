class Solution {
    func removeZeros(_ n: Int) -> Int {
        let result = String(n).replacingOccurrences(of: "0", with: "")
        return Int(result)!
    }
}