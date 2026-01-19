function maxSideLength(mat: number[][], threshold: number): number {
    const m = mat.length,
        n = mat[0].length;
    const P: number[][] = Array.from({ length: m + 1 }, () =>
        new Array(n + 1).fill(0),
    );

    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            P[i][j] =
                P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + mat[i - 1][j - 1];
        }
    }

    const getRect = (
        x1: number,
        y1: number,
        x2: number,
        y2: number,
    ): number => {
        return P[x2][y2] - P[x1 - 1][y2] - P[x2][y1 - 1] + P[x1 - 1][y1 - 1];
    };

    const r = Math.min(m, n);
    let ans = 0;
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            for (let c = ans + 1; c <= r; c++) {
                if (
                    i + c - 1 <= m &&
                    j + c - 1 <= n &&
                    getRect(i, j, i + c - 1, j + c - 1) <= threshold
                ) {
                    ans = c;
                } else {
                    break;
                }
            }
        }
    }
    return ans;
}