class Solution {
    func shortestDistanceAfterQueries(_ n: Int, _ queries: [[Int]]) -> [Int] {
        var adj = Array(repeating: [Int](), count: n)
        for i in 0..<n {
            adj[i] = [i + 1]
        }
        
        func shortestPath() -> Int {
            var queue = [(0, 0)] // node, length
            var visit = Set<Int>()
            visit.insert(0)
            var queueIndex = 0
            
            while queueIndex < queue.count {
                let (cur, length) = queue[queueIndex]
                queueIndex += 1
                
                if cur == n - 1 {
                    return length
                }
                
                for nei in adj[cur] {
                    if !visit.contains(nei) {
                        queue.append((nei, length + 1))
                        visit.insert(nei)
                    }
                }
            }
            return -1
        }
        
        var res = [Int]()
        for query in queries {
            let src = query[0], dst = query[1]
            adj[src].append(dst)
            res.append(shortestPath())
        }
        return res
    }
}