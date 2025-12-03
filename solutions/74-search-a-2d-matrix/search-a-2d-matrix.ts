function searchMatrix(matrix: number[][], target: number): boolean {
    let m = matrix.length;
    if (m == 0) return false;
    let n = matrix[0].length;
    let left = 0,
        right = m * n - 1;
    let pivotIdx, pivotElement;
    while (left <= right) {
        pivotIdx = Math.floor((left + right) / 2);
        pivotElement = matrix[Math.floor(pivotIdx / n)][pivotIdx % n];
        if (target == pivotElement) return true;
        else {
            if (target < pivotElement) right = pivotIdx - 1;
            else left = pivotIdx + 1;
        }
    }
    return false;
}