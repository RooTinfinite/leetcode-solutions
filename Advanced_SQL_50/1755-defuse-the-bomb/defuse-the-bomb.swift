class Solution {
    func decrypt(_ code: [Int], _ k: Int) -> [Int] {
        let N = code.count
        var res = Array(repeating: 0, count: N)
        
        if k == 0 { return res }
        
        var l = 0
        var curSum = 0
        for r in 0..<(N + abs(k)) {
            curSum += code[r % N]
            
            if r - l + 1 > abs(k) {
                curSum -= code[l % N]
                l = (l + 1) % N
            }
            
            if r - l + 1 == abs(k) {
                if k > 0 {
                    res[((l - 1 + N) % N)] = curSum
                } else {
                    res[(r + 1) % N] = curSum
                }
            }
        }
        return res
    }
}