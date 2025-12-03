func setZeroes(matrix [][]int) {
    isCol := false
    R := len(matrix)
    C := len(matrix[0])
    for i := 0; i < R; i++ {
        if matrix[i][0] == 0 {
            isCol = true
        }
        for j := 1; j < C; j++ {
            if matrix[i][j] == 0 {
                matrix[0][j] = 0
                matrix[i][0] = 0
            }
        }
    }
    for i := 1; i < R; i++ {
        for j := 1; j < C; j++ {
            if matrix[i][0] == 0 || matrix[0][j] == 0 {
                matrix[i][j] = 0
            }
        }
    }
    if matrix[0][0] == 0 {
        for j := 0; j < C; j++ {
            matrix[0][j] = 0
        }
    }
    if isCol {
        for i := 0; i < R; i++ {
            matrix[i][0] = 0
        }
    }
}