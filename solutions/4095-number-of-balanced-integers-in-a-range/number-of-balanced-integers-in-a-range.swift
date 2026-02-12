final class Solution {
    func countBalanced(_ low: Int, _ high: Int) -> Int {
        func solve(_ x: Int) -> Int {
            if x < 0 { return 0 }
            let digits = Array(String(x)).map { Int(String($0))! }
            let n = digits.count
            let offset = 9 * n
            let size = offset * 2 + 1

            var memo = Array(repeating: Array(repeating: Array(repeating: Int.min, count: size), count: 2), count: n + 1)

            func dfs(_ idx: Int, _ tight: Int, _ diff: Int) -> Int {
                if idx == n { return diff == 0 ? 1 : 0 }
                let key = diff + offset
                if memo[idx][tight][key] != Int.min { return memo[idx][tight][key] }

                let sign = (idx & 1) == 0 ? 1 : -1
                let ub = tight == 1 ? digits[idx] : 9
                var res = 0

                for d in 0...ub {
                    let nt = (tight == 1 && d == ub) ? 1 : 0
                    res += dfs(idx + 1, nt, diff + sign * d)
                }

                memo[idx][tight][key] = res
                return res
            }

            return dfs(0, 1, 0)
        }

        return solve(high) - solve(low - 1)
    }
}