package main

import "container/heap"

type State struct {
    dist int64
    node int
    cnt  int
}

type PQ []State

func (p PQ) Len() int            { return len(p) }
func (p PQ) Less(i, j int) bool  { return p[i].dist < p[j].dist }
func (p PQ) Swap(i, j int)       { p[i], p[j] = p[j], p[i] }
func (p *PQ) Push(x interface{}) { *p = append(*p, x.(State)) }
func (p *PQ) Pop() interface{} {
    old := *p
    n := len(old)
    item := old[n-1]
    *p = old[:n-1]
    return item
}
func shortestPath(n int, edges [][]int, labels string, k int) int {
    const INF = int64(1) << 60

    adj := make([][][2]int, n)
    for _, e := range edges {
        adj[e[0]] = append(adj[e[0]], [2]int{e[1], e[2]})
    }

    dist := make([][]int64, n)
    for i := range dist {
        dist[i] = make([]int64, k+1)
        for j := range dist[i] {
            dist[i][j] = INF
        }
    }

    dist[0][1] = 0
    pq := &PQ{}
    *pq = append(*pq, State{0, 0, 1})
    heap.Init(pq)

    for pq.Len() > 0 {
        cur := heap.Pop(pq).(State)
        d, u, run := cur.dist, cur.node, cur.cnt
        if d != dist[u][run] {
            continue
        }
        for _, vec := range adj[u] {
            v, w := vec[0], vec[1]
            newRun := 1
            if labels[v] == labels[u] {
                newRun = run + 1
            }
            if newRun > k {
                continue
            }
            if dist[v][newRun] > d+int64(w) {
                dist[v][newRun] = d + int64(w)
                heap.Push(pq, State{dist[v][newRun], v, newRun})
            }
        }
    }

    ans := INF
    for i := 1; i <= k; i++ {
        if dist[n-1][i] < ans {
            ans = dist[n-1][i]
        }
    }
    if ans == INF {
        return -1
    }
    return int(ans)
}