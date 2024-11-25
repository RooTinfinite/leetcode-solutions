func validArrangement(pairs [][]int) [][]int {
    // Create adjacency list and in/out degree maps
    adjacencyList := make(map[int][]int)
    inOutDegree := make(map[int]int)
    
    // Build graph and count in/out degrees
    for _, pair := range pairs {
        adjacencyList[pair[0]] = append(adjacencyList[pair[0]], pair[1])
        inOutDegree[pair[0]]++  // out-degree
        inOutDegree[pair[1]]--  // in-degree
    }
    
    // Find starting node
    startNode := pairs[0][0]
    for node, degree := range inOutDegree {
        if degree == 1 {
            startNode = node
            break
        }
    }
    
    // Use slice as stack for path
    path := []int{}
    nodeStack := []int{startNode}
    
    for len(nodeStack) > 0 {
        lastIdx := len(nodeStack) - 1
        curr := nodeStack[lastIdx]
        neighbors := adjacencyList[curr]
        
        if len(neighbors) == 0 {
            path = append(path, curr)
            nodeStack = nodeStack[:lastIdx]
        } else {
            nextNode := neighbors[len(neighbors)-1]
            nodeStack = append(nodeStack, nextNode)
            adjacencyList[curr] = neighbors[:len(neighbors)-1]
        }
    }
    
    // Build final arrangement
    arrangement := make([][]int, 0, len(path)-1)
    for i := len(path) - 1; i > 0; i-- {
        arrangement = append(arrangement, []int{path[i], path[i-1]})
    }
    
    return arrangement
}