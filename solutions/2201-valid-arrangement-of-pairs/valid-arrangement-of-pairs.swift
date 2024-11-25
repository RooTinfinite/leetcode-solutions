// Ver. Eulerian path + Hierholzer's algorithm 193ms 
// (Swift like that https://github.com/swiftlang/swift/blob/main/docs/OptimizationTips.rst)
class Solution {
    func validArrangement(_ pairs: [[Int]]) -> [[Int]] {
        // build a graph
        var adjList: [Int:[Int]] = [:]
        var inDegree: [Int:Int] = [:]
        for pair in pairs {
            adjList[pair[0], default:[]].append(pair[1])
            inDegree[pair[1], default:0] += 1
        }
        // Eulerian path
        var start = pairs[0][0] 
        for (v, outEdges) in adjList {
            if outEdges.count - inDegree[v, default:0] == 1 { 
                start = v; break 
            }
        }
        
        // Hierholzer's algorithm
        var path: [[Int]] = []
        func traverse(from vertex: Int) {
            while let next = adjList[vertex]?.popLast() {
                traverse(from: next)
                path.append([vertex, next])
            }
        }
        
        traverse(from: start)
        path.reverse()
        return path
    }
}