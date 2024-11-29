package main

import (
    "container/heap"
    "fmt"
)

type MinHeap [][]int

func (h MinHeap) Len() int           { return len(h) }
func (h MinHeap) Less(i, j int) bool { return h[i][0] < h[j][0] }
func (h MinHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MinHeap) Push(x interface{}) {
    *h = append(*h, x.([]int))
}

func (h *MinHeap) Pop() interface{} {
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[0 : n-1]
    return x
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}
func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func minimumTime(grid [][]int) int {
    if min(grid[0][1], grid[1][0]) > 1 {
        return -1
    }
    
    rows, cols := len(grid), len(grid[0])
    minHeap := &MinHeap{}
    heap.Init(minHeap)
    heap.Push(minHeap, []int{0, 0, 0}) // time, r, c
    visited := make(map[string]bool)
    
    dirs := [][]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
    
    for minHeap.Len() > 0 {
        curr := heap.Pop(minHeap).([]int)
        t, r, c := curr[0], curr[1], curr[2]
        
        if r == rows-1 && c == cols-1 {
            return t
        }
        
        for _, dir := range dirs {
            nr, nc := r+dir[0], c+dir[1]
            key := fmt.Sprintf("%d,%d", nr, nc)
            
            if nr < 0 || nc < 0 || nr == rows || nc == cols || visited[key] {
                continue
            }
            
            wait := 0
            if abs(grid[nr][nc]-t)%2 == 0 {
                wait = 1
            }
            nTime := max(grid[nr][nc]+wait, t+1)
            heap.Push(minHeap, []int{nTime, nr, nc})
            visited[key] = true
        }
    }
    return -1
}