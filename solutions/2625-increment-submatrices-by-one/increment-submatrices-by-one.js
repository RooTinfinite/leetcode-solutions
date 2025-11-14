var rangeAddQueries = function (n, queries) {
    let diff = Array.from({ length: n + 1 }, () => Array(n + 1).fill(0));
    for (let [row1, col1, row2, col2] of queries) {
        diff[row1][col1] += 1;
        diff[row2 + 1][col1] -= 1;
        diff[row1][col2 + 1] -= 1;
        diff[row2 + 1][col2 + 1] += 1;
    }

    let mat = Array.from({ length: n }, () => Array(n).fill(0));
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            let x1 = i === 0 ? 0 : mat[i - 1][j];
            let x2 = j === 0 ? 0 : mat[i][j - 1];
            let x3 = i === 0 || j === 0 ? 0 : mat[i - 1][j - 1];
            mat[i][j] = diff[i][j] + x1 + x2 - x3;
        }
    }
    return mat;
};