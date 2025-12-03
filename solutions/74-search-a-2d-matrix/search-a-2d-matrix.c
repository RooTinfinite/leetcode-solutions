bool searchMatrix(int** matrix, int matrixRowSize, int* matrixColSize,
                  int target) {
    if (matrixRowSize == 0) return false;
    int n = matrixColSize[0];
    int left = 0, right = matrixRowSize * n - 1;
    int pivotIdx, pivotElement;
    while (left <= right) {
        pivotIdx = (left + right) / 2;
        pivotElement = matrix[pivotIdx / n][pivotIdx % n];
        if (target == pivotElement)
            return true;
        else {
            if (target < pivotElement)
                right = pivotIdx - 1;
            else
                left = pivotIdx + 1;
        }
    }
    return false;
}