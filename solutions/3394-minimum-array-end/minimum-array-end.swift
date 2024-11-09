class Solution {
    func minEnd(_ n: Int, _ x: Int) -> Int {
        var result = Int64(x)
        var remaining = Int64(n - 1)
        var position: Int64 = 1
        
        while remaining != 0 {
            if (Int64(x) & position) == 0 {
                result |= (remaining & 1) * position
                remaining >>= 1
            }
            position <<= 1
        }
        
        return Int(result)
    }
}