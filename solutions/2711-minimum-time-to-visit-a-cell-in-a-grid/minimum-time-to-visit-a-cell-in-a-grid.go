type Cell struct {
    time, row, col int
}

type PriorityQueue []Cell

func (pq PriorityQueue) Len() int { return len(pq) }
func (pq PriorityQueue) Less(i, j int) bool { return pq[i].time < pq[j].time }
func (pq PriorityQueue) Swap(i, j int) { pq[i], pq[j] = pq[j], pq[i] }
func (pq *PriorityQueue) Push(x interface{}) { *pq = append(*pq, x.(Cell)) }
func (pq *PriorityQueue) Pop() interface{} {
    old := *pq
    n := len(old)
    item := old[n-1]
    *pq = old[0 : n-1]
    return item
}

func minimumTime(grid [][]int) int {
    if grid[0][1] > 1 && grid[1][0] > 1 {
        return -1
    }
    
    rows, cols := len(grid), len(grid[0])
    minHeap := &PriorityQueue{}
    heap.Init(minHeap)
    heap.Push(minHeap, Cell{0, 0, 0})
    
    seen := make([][]int, rows)
    for i := range seen {
        seen[i] = make([]int, cols)
    }
    seen[0][0] = 1
    
    moves := [][2]int{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}
    
    for minHeap.Len() > 0 {
        curr := heap.Pop(minHeap).(Cell)
        currTime := curr.time
        currRow := curr.row
        currCol := curr.col
        
        if currRow == rows-1 && currCol == cols-1 {
            return currTime
        }
        
        for _, move := range moves {
            nextRow := move[0] + currRow
            nextCol := move[1] + currCol
            
            if nextRow >= 0 && nextCol >= 0 && 
               nextRow < rows && nextCol < cols && 
               seen[nextRow][nextCol] == 0 {
                
                waitTime := 0
                if (grid[nextRow][nextCol]-currTime)%2 == 0 {
                    waitTime = 1
                }
                nextTime := max(currTime+1, grid[nextRow][nextCol]+waitTime)
                
                heap.Push(minHeap, Cell{nextTime, nextRow, nextCol})
                seen[nextRow][nextCol] = 1
            }
        }
    }
    return -1
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}