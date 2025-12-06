type MyCircularQueue struct {
    queue     []int
    tailIndex int
    capacity  int
}

func CreateMyCircularQueue(capacity int) MyCircularQueue {
    return MyCircularQueue{make([]int, capacity), 0, capacity}
}

func (q *MyCircularQueue) enQueue(value int) {
    q.queue[q.tailIndex] = value
    q.tailIndex = (q.tailIndex + 1) % q.capacity
}

func (q *MyCircularQueue) get(index int) int {
    return q.queue[index%q.capacity]
}

func calculateMinimumHP(dungeon [][]int) int {
    rows := len(dungeon)
    cols := len(dungeon[0])
    dp := CreateMyCircularQueue(cols)
    inf := int(^uint(0) >> 1)

    getMinHealth := func(currCell, nextRow, nextCol int) int {
        if nextRow < 0 || nextCol < 0 {
            return inf
        }

        index := cols*nextRow + nextCol
        nextCell := dp.get(index)
        return max(1, nextCell-currCell)
    }

    for row := 0; row < rows; row++ {
        for col := 0; col < cols; col++ {
            currCell := dungeon[rows-row-1][cols-col-1]
            rightHealth := getMinHealth(currCell, row, col-1)
            downHealth := getMinHealth(currCell, row-1, col)
            nextHealth := min(rightHealth, downHealth)

            minHealth := 0
            if nextHealth != inf {
                minHealth = nextHealth
            } else {
                if currCell >= 0 {
                    minHealth = 1
                } else {
                    minHealth = 1 - currCell
                }
            }

            dp.enQueue(minHealth)
        }
    }

    return dp.get(cols - 1)
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}