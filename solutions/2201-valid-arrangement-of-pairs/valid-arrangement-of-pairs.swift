class Solution {
    func validArrangement(_ pairs: [[Int]]) -> [[Int]] {
        let capacity = pairs.count
        var adjacencyList = Dictionary<Int, [Int]>(minimumCapacity: capacity)
        var inOutDegree = Dictionary<Int, Int>(minimumCapacity: capacity * 2)
        
        for pair in pairs {
            adjacencyList[pair[0], default: []].append(pair[1])
            inOutDegree[pair[0], default: 0] += 1
            inOutDegree[pair[1], default: 0] -= 1
        }
        
        // start node finding
        let startNode = inOutDegree.first { $0.value == 1 }?.key ?? pairs[0][0]
        
        var path = [Int]()
        path.reserveCapacity(capacity + 1)
        var nodeStack = [Int]()
        nodeStack.reserveCapacity(capacity)
        nodeStack.append(startNode)
        
        while let currentNode = nodeStack.last {
            guard var neighbors = adjacencyList[currentNode], !neighbors.isEmpty else {
                path.append(nodeStack.removeLast())
                continue
            }
            
            let nextNode = neighbors.removeLast()
            adjacencyList[currentNode] = neighbors
            nodeStack.append(nextNode)
        }
        
        return stride(from: path.count - 1, to: 0, by: -1).map { i in
            [path[i], path[i-1]]
        }
    }
}