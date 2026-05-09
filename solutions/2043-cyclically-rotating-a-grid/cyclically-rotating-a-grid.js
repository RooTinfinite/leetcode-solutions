var rotateGrid = function (grid, k) {
    const m = grid.length;
    const n = grid[0].length;
    const nlayer = Math.min(Math.floor(m / 2), Math.floor(n / 2)); // level count
    // enumerate each layer counterclockwise starting from the top-left corner
    for (let layer = 0; layer < nlayer; ++layer) {
        const r = [];
        const c = [];
        const val = []; // each element's row index, column index, and value
        for (let i = layer; i < m - layer - 1; ++i) {
            // left
            r.push(i);
            c.push(layer);
            val.push(grid[i][layer]);
        }
        for (let j = layer; j < n - layer - 1; ++j) {
            // down
            r.push(m - layer - 1);
            c.push(j);
            val.push(grid[m - layer - 1][j]);
        }
        for (let i = m - layer - 1; i > layer; --i) {
            // right
            r.push(i);
            c.push(n - layer - 1);
            val.push(grid[i][n - layer - 1]);
        }
        for (let j = n - layer - 1; j > layer; --j) {
            // up
            r.push(layer);
            c.push(j);
            val.push(grid[layer][j]);
        }
        const total = val.length; // total number of elements in each layer
        const kk = k % total; // equivalent number of rotations
        // find the value at each index after rotation
        for (let i = 0; i < total; ++i) {
            const idx = (i + total - kk) % total; // the index corresponding to the value after rotation
            grid[r[i]][c[i]] = val[idx];
        }
    }
    return grid;
};