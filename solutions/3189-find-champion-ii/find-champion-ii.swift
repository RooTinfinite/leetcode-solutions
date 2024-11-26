class Solution {
    func findChampion(_ n: Int, _ edges: [[Int]]) -> Int {
        var isUndefeated = Array(repeating: true, count: n)
        
        for edge in edges {
            let winner = edge[0], loser = edge[1]
            isUndefeated[loser] = false
        }
        
        var champion = -1
        var championCount = 0
        
        for team in 0..<n {
            if isUndefeated[team] {
                champion = team
                championCount += 1
            }
        }
        
        return championCount == 1 ? champion : -1
    }
}