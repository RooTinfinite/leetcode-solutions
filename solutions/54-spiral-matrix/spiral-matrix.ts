function spiralOrder(matrix: number[][]): number[] {
    const VISITED = 101;
    let rows = matrix.length,
        cols = matrix[0].length;
    let result: number[] = [matrix[0][0]];
    matrix[0][0] = VISITED;
    // Four directions that we will move: right, down, left, up.
    let directions: number[][] = [
        [0, 1],
        [1, 0],
        [0, -1],
        [-1, 0],
    ];
    // Initial direction: moving right.
    let currentDirection = 0;
    // The number of times we change the direction.
    let changeDirection = 0;
    let row = 0,
        col = 0;
    while (changeDirection < 2) {
        while (
            row + directions[currentDirection][0] >= 0 &&
            row + directions[currentDirection][0] < rows &&
            col + directions[currentDirection][1] >= 0 &&
            col + directions[currentDirection][1] < cols &&
            matrix[row + directions[currentDirection][0]][
                col + directions[currentDirection][1]
            ] != VISITED
        ) {
            // Reset this to 0 since we did not break and change the direction.
            changeDirection = 0;
            // Calculate the next place that we will move to.
            row += directions[currentDirection][0];
            col += directions[currentDirection][1];
            result.push(matrix[row][col]);
            matrix[row][col] = VISITED;
        }
        // Change our direction.
        currentDirection = (currentDirection + 1) % 4;
        // Increment changeDirection because we changed our direction.
        changeDirection++;
    }
    return result;
}