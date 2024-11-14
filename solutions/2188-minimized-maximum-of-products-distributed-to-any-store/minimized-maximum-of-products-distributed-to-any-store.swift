class Solution {
    func minimizedMaximum(_ n: Int, _ quantities: [Int]) -> Int {
        func canDistribute(_ x: Int) -> Bool {
            var stores = 0
            for q in quantities {
                stores += (q + x - 1) / x
            }
            return stores <= n
        }
        
        var left = 1
        var right = quantities.max()!
        var result = 0
        
        while left <= right {
            let x = (left + right) / 2
            if canDistribute(x) {
                result = x
                right = x - 1
            } else {
                left = x + 1
            }
        }
        
        return result
    }
}