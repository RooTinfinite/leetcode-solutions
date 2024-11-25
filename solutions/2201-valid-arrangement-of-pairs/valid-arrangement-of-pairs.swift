class Solution {
    func validArrangement(_ pairs: [[Int]]) -> [[Int]] {
        let capacity = pairs.count
        var adjList = Dictionary<Int, [Int]>(minimumCapacity: capacity)
        var inDegree = Dictionary<Int, Int>(minimumCapacity: capacity)
        
        // Single-pass graph building with pre-allocated capacity
        for pair in pairs {
            adjList[pair[0], default: []].append(pair[1])
            inDegree[pair[1], default: 0] += 1
        }
        
        // Efficient start vertex finding
        let start = adjList.first { vertex in 
            vertex.value.count - inDegree[vertex.key, default: 0] == 1 
        }?.key ?? pairs[0][0]
        
        // Pre-allocated result array
        var path = [[Int]]()
        path.reserveCapacity(capacity)
        
        // Optimized Hierholzer's algorithm implementation
        func traverse(from vertex: Int) {
            while var neighbors = adjList[vertex], !neighbors.isEmpty {
                let next = neighbors.removeLast()
                adjList[vertex] = neighbors
                traverse(from: next)
                path.append([vertex, next])
            }
        }
        
        traverse(from: start)
        path.reverse()
        return path
    }
}