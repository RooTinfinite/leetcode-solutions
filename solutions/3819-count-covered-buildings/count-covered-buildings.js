var countCoveredBuildings = function (n, buildings) {
    const maxRow = new Array(n + 1).fill(0);
    const minRow = new Array(n + 1).fill(n + 1);
    const maxCol = new Array(n + 1).fill(0);
    const minCol = new Array(n + 1).fill(n + 1);

    for (const p of buildings) {
        const x = p[0],
            y = p[1];
        maxRow[y] = Math.max(maxRow[y], x);
        minRow[y] = Math.min(minRow[y], x);
        maxCol[x] = Math.max(maxCol[x], y);
        minCol[x] = Math.min(minCol[x], y);
    }

    let res = 0;
    for (const p of buildings) {
        const x = p[0],
            y = p[1];
        if (x > minRow[y] && x < maxRow[y] && y > minCol[x] && y < maxCol[x]) {
            res++;
        }
    }

    return res;
};