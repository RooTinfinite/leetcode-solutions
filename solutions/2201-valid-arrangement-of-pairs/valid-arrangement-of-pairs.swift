class Solution {
    func validArrangement(_ pairs: [[Int]]) -> [[Int]] {
        // Build adjacency list and track degrees
        var adjacencyList: [Int: [Int]] = [:]
        var inOutDegree: [Int: Int] = [:]
        
        // Construct graph
        for pair in pairs {
            adjacencyList[pair[0], default: []].append(pair[1])
            inOutDegree[pair[0], default: 0] += 1
            inOutDegree[pair[1], default: 0] -= 1
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
            if var neighbors = adjacencyList[nodeStack.last!], !neighbors.isEmpty {
                let nextNode = neighbors.removeLast()
                adjacencyList[nodeStack.last!] = neighbors
                nodeStack.append(nextNode)
            } else {
                path.append(nodeStack.removeLast())
            }
        }
        
        // Construct final arrangement
        var arrangement: [[Int]] = []
        arrangement.reserveCapacity(path.count - 1)
        
        for i in stride(from: path.count - 1, to: 0, by: -1) {
            arrangement.append([path[i], path[i-1]])
        }
        
        return arrangement
    }
}