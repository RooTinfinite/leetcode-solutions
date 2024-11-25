class Solution {
    func validArrangement(_ pairs: [[Int]]) -> [[Int]] {
        var adjacencyList: [Int: [Int]] = [:]
        var inOutDegree: [Int: Int] = [:]
        
        // Build graph and count in/out degrees
        for pair in pairs {
            adjacencyList[pair[0], default: []].append(pair[1])
            inOutDegree[pair[0], default: 0] += 1  // out-degree
            inOutDegree[pair[1], default: 0] -= 1  // in-degree
        }
        
        // Find starting node
        var startNode = pairs[0][0]
        for (node, degree) in inOutDegree {
            if degree == 1 {
                startNode = node
                break
            }
        }
        
        var path: [Int] = []
        var nodeStack: [Int] = [startNode]
        
        while !nodeStack.isEmpty {
            if var neighbors = adjacencyList[nodeStack.last!] {
                if neighbors.isEmpty {
                    path.append(nodeStack.removeLast())
                } else {
                    let nextNode = neighbors.removeLast()
                    adjacencyList[nodeStack.last!] = neighbors
                    nodeStack.append(nextNode)
                }
            } else {
                path.append(nodeStack.removeLast())
            }
        }
        
        var arrangement: [[Int]] = []
        let pathSize = path.count
        arrangement.reserveCapacity(pathSize - 1)
        
        for i in stride(from: pathSize - 1, to: 0, by: -1) {
            arrangement.append([path[i], path[i-1]])
        }
        
        return arrangement
    }
}