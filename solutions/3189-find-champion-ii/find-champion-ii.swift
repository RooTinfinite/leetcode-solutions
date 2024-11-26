class Solution {
    func findChampion(_ n: Int, _ edges: [[Int]]) -> Int {
        var incoming = Array(repeating: 0, count: n)
        
        for edge in edges {
            incoming[edge[1]] += 1
        }
        
        var champions: [Int] = []
        for (i, count) in incoming.enumerated() {
            if count == 0 {
                champions.append(i)
            }
        }
        
        return champions.count > 1 ? -1 : champions[0]
    }
}