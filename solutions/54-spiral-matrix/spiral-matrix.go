func spiralOrder(matrix [][]int) []int {
    const VISITED = 101
    rows, cols := len(matrix), len(matrix[0])
    result := []int{matrix[0][0]}
    matrix[0][0] = VISITED
    // Four directions that we will move: right, down, left, up.
    directions := [4][2]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}
    // Initial direction: moving right.
    currentDirection := 0
    // The number of times we change the direction.
    changeDirection := 0
    row, col := 0, 0
    for changeDirection < 2 {
        for row+directions[currentDirection][0] >= 0 &&
            row+directions[currentDirection][0] < rows &&
            col+directions[currentDirection][1] >= 0 &&
            col+directions[currentDirection][1] < cols &&
            matrix[row+directions[currentDirection][0]][col+directions[currentDirection][1]] != VISITED {
            // Reset this to 0 since we did not break and change the direction.
            changeDirection = 0
            // Calculate the next place that we will move to.
            row += directions[currentDirection][0]
            col += directions[currentDirection][1]
            result = append(result, matrix[row][col])
            matrix[row][col] = VISITED
        }
        // Change our direction.
        currentDirection = (currentDirection + 1) % 4
        // Increment changeDirection because we changed our direction.
        changeDirection++
    }
    return result
}