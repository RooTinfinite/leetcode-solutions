class Solution {
    func decrypt(_ circ: [Int], _ k: Int) -> [Int] {
        let n = circ.count
        var result = Array(repeating: 0, count: n)
        
        if k == 0 { return result }
        
        var wSum = 0
        let start = k > 0 ? 1 : n + k
        let end = k > 0 ? k : n - 1
        
        for i in start...end {
            wSum += circ[i % n]
        }
        
        for i in 0..<n {
            result[i] = wSum
            wSum -= circ[(start + i) % n]
            wSum += circ[(end + i + 1) % n]
        }
        
        return result
    }
}