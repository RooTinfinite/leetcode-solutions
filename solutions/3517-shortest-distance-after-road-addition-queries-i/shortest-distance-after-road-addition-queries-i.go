func updateDistances(graph [][]int, current int, distances []int) {
    newDist := distances[current] + 1
    
    for _, neighbor := range graph[current] {
        if distances[neighbor] <= newDist {
            continue
        }
        
        distances[neighbor] = newDist
        updateDistances(graph, neighbor, distances)
    }
}

func shortestDistanceAfterQueries(n int, queries [][]int) []int {
    distances := make([]int, n)
    for i := range distances {
        distances[i] = n - 1 - i
    }
    
    graph := make([][]int, n)
    for i := 0; i < n-1; i++ {
        graph[i+1] = append(graph[i+1], i)
    }
    
    answer := make([]int, 0, len(queries))
    
    for _, query := range queries {
        source, target := query[0], query[1]
        graph[target] = append(graph[target], source)
        
        if distances[target]+1 < distances[source] {
            distances[source] = distances[target] + 1
        }
        
        updateDistances(graph, source, distances)
        answer = append(answer, distances[0])
    }
    
    return answer
}