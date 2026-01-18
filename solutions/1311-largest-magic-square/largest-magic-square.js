var largestMagicSquare = function (grid) {
    const m = grid.length,
        n = grid[0].length;
    // prefix sum of each row
    const rowsum = Array.from({ length: m }, () => new Array(n));
    for (let i = 0; i < m; ++i) {
        rowsum[i][0] = grid[i][0];
        for (let j = 1; j < n; ++j) {
            rowsum[i][j] = rowsum[i][j - 1] + grid[i][j];
        }
    }
    // prefix sum of each column
    const colsum = Array.from({ length: m }, () => new Array(n));
    for (let j = 0; j < n; ++j) {
        colsum[0][j] = grid[0][j];
        for (let i = 1; i < m; ++i) {
            colsum[i][j] = colsum[i - 1][j] + grid[i][j];
        }
    }

    // enumerate edge lengths from largest to smallest
    for (let edge = Math.min(m, n); edge >= 2; --edge) {
        // enumerate the top-left corner position (i,j) of the square
        for (let i = 0; i + edge <= m; ++i) {
            for (let j = 0; j + edge <= n; ++j) {
                // calculate the standard value
                let stdsum =
                    rowsum[i][j + edge - 1] - (j > 0 ? rowsum[i][j - 1] : 0);
                let check = true;
                // check each row
                for (let ii = i + 1; ii < i + edge; ++ii) {
                    let sum =
                        rowsum[ii][j + edge - 1] -
                        (j > 0 ? rowsum[ii][j - 1] : 0);
                    if (sum !== stdsum) {
                        check = false;
                        break;
                    }
                }
                if (!check) continue;
                // check each column
                for (let jj = j; jj < j + edge; ++jj) {
                    let sum =
                        colsum[i + edge - 1][jj] -
                        (i > 0 ? colsum[i - 1][jj] : 0);
                    if (sum !== stdsum) {
                        check = false;
                        break;
                    }
                }
                if (!check) continue;
                // check the diagonal
                let d1 = 0,
                    d2 = 0;
                for (let k = 0; k < edge; ++k) {
                    d1 += grid[i + k][j + k];
                    d2 += grid[i + k][j + edge - 1 - k];
                }
                if (d1 === stdsum && d2 === stdsum) {
                    return edge;
                }
            }
        }
    }
    return 1;
};