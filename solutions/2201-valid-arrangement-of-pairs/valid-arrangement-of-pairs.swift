// + Hierholzers algorithm
class Solution {
    func validArrangement(_ pairs: [[Int]]) -> [[Int]] {
        var adjList = [Int: [Int]]()
        var inDegree = [Int: Int]()
        
        // Build graph
        for pair in pairs {
            adjList[pair[0], default: []].append(pair[1])
            inDegree[pair[1], default: 0] += 1
        }
        
        // Find start vertex
        var start = pairs[0][0]
        for (v, outEdges) in adjList {
            if outEdges.count - (inDegree[v] ?? 0) == 1 {
                start = v
                break
            }
        }
        
        var path = [[Int]]()
        var stack = [start]
        
        while !stack.isEmpty {
            let current = stack.last!
            if var neighbors = adjList[current], !neighbors.isEmpty {
                let next = neighbors.removeLast()
                adjList[current] = neighbors
                stack.append(next)
            } else {
                let vertex = stack.removeLast()
                if !stack.isEmpty {
                    path.append([stack.last!, vertex])
                }
            }
        }
        
        return path.reversed()
    }
}