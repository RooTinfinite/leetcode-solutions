class Solution {
    func combinationSum(_ candidates: [Int], _ target: Int) -> [[Int]] {
        let count = candidates.count
        var sol = [Int]()
        var res = [[Int]]()

        func backtrack(_ index: Int) {
            guard index < count else { return }

            let sum = sol.reduce(0, +)

            guard sum < target else {
                if sum == target {
                    res.append(sol)
                }

                return
            }

            sol.append(candidates[index])
            backtrack(index)
            sol.popLast()

            backtrack(index + 1)
        }
        
        backtrack(0)
        return res
    }
}