class Solution {
    func validArrangement(_ pairs: [[Int]]) -> [[Int]] {
        var adjList = Dictionary<Int, [Int]>(minimumCapacity: pairs.count)
        var inDegree = Dictionary<Int, Int>(minimumCapacity: pairs.count)
        
        for pair in pairs {
            adjList[pair[0], default: []].append(pair[1])
            inDegree[pair[1], default: 0] += 1
        }
        

        let start = adjList.first { vertex in
            vertex.value.count - inDegree[vertex.key, default: 0] == 1
        }?.key ?? pairs[0][0]
        
        var path = [[Int]]()
        path.reserveCapacity(pairs.count)
        
        func traverse(from vertex: Int) {
            while var edges = adjList[vertex], !edges.isEmpty {
                let next = edges.removeLast()
                adjList[vertex] = edges
                traverse(from: next)
                path.append([vertex, next])
            }
        }
        
        traverse(from: start)
        path.reverse()
        return path
    }
}