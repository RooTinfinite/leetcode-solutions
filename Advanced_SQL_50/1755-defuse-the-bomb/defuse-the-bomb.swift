class Solution {
    func decrypt(_ code: [Int], _ k: Int) -> [Int] {
        let N = code.count
        var res = Array(repeating: 0, count: N)
        
        for i in 0..<N {
            if k > 0 {
                for j in (i + 1)...(i + k) {
                    res[i] += code[j % N]
                }
            } else if k < 0 {
                for j in stride(from: i - 1, through: i - abs(k), by: -1) {
                    res[i] += code[((j % N) + N) % N]
                }
            }
        }
        
        return res
    }
}