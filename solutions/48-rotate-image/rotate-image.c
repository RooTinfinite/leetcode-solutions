void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int temp, n = matrixSize;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - j - 1];
            matrix[i][n - j - 1] = temp;
        }
    }
}