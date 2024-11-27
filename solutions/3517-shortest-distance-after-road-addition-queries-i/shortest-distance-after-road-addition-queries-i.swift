class Solution {
    func updateDistances(_ graph: [[Int]], _ current: Int, _ distances: inout [Int]) {
        let newDist = distances[current] + 1
        
        for neighbor in graph[current] {
            if distances[neighbor] <= newDist {
                continue
            }
            
            distances[neighbor] = newDist
            updateDistances(graph, neighbor, &distances)
        }
    }
    
    func shortestDistanceAfterQueries(_ n: Int, _ queries: [[Int]]) -> [Int] {
        var distances = (0..<n).map { n - 1 - $0 }
        
        var graph = Array(repeating: [Int](), count: n)
        for i in 0..<(n-1) {
            graph[i + 1].append(i)
        }
        
        var answer = [Int]()
        
        for query in queries {
            let source = query[0]
            let target = query[1]
            
            graph[target].append(source)
            distances[source] = min(distances[source], distances[target] + 1)
            updateDistances(graph, source, &distances)
            
            answer.append(distances[0])
        }
        
        return answer
    }
}