func uniquePathsWithObstacles(obstacleGrid [][]int) int {
    R := len(obstacleGrid)
    C := len(obstacleGrid[0])
    // If the starting cell has an obstacle, then simply return as there would be
    // no paths to the destination.
    if obstacleGrid[0][0] == 1 {
        return 0
    }
    // Number of ways of reaching the starting cell = 1.
    obstacleGrid[0][0] = 1
    // Filling the values for the first column
    for i := 1; i < R; i++ {
        if obstacleGrid[i][0] == 0 && obstacleGrid[i-1][0] == 1 {
            obstacleGrid[i][0] = 1
        } else {
            obstacleGrid[i][0] = 0
        }
    }
    // Filling the values for the first row
    for i := 1; i < C; i++ {
        if obstacleGrid[0][i] == 0 && obstacleGrid[0][i-1] == 1 {
            obstacleGrid[0][i] = 1
        } else {
            obstacleGrid[0][i] = 0
        }
    }
    // Starting from cell(1,1) fill up the values
    // No. of ways of reaching cell[i][j] = cell[i - 1][j] + cell[i][j - 1]
    // i.e. From above and left.
    for i := 1; i < R; i++ {
        for j := 1; j < C; j++ {
            if obstacleGrid[i][j] == 0 {
                obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1]
            } else {
                obstacleGrid[i][j] = 0
            }
        }
    }
    // Return value stored in rightmost bottommost cell. That is the destination.
    return obstacleGrid[R-1][C-1]
}