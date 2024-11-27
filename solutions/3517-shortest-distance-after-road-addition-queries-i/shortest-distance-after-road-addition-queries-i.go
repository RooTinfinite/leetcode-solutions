func shortestDistanceAfterQueries(n int, queries [][]int) []int {
    adj := make([][]int, n)
    for i := range adj {
        adj[i] = []int{i + 1}
    }
    
    shortestPath := func() int {
        q := [][]int{{0, 0}} // node, length
        visit := make(map[int]bool)
        visit[0] = true
        
        for len(q) > 0 {
            cur, length := q[0][0], q[0][1]
            q = q[1:]
            
            if cur == n-1 {
                return length
            }
            
            for _, nei := range adj[cur] {
                if !visit[nei] {
                    q = append(q, []int{nei, length + 1})
                    visit[nei] = true
                }
            }
        }
        return -1
    }
    
    res := make([]int, 0)
    for _, query := range queries {
        src, dst := query[0], query[1]
        adj[src] = append(adj[src], dst)
        res = append(res, shortestPath())
    }
    return res
}