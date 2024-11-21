function countUnguarded(m: number, n: number, guards: number[][], walls: number[][]): number {
    const grid: number[][] = Array(m).fill(0).map(() => Array(n).fill(0));
    // 0 = free, 1 = guard, 2 = wall, 3 = guardable

    for (const [r, c] of guards) {
        grid[r][c] = 1;
    }
    for (const [r, c] of walls) {
        grid[r][c] = 2;
    }

    const markGuarded = (r: number, c: number): void => {
        for (let row = r + 1; row < m; row++) {
            if (grid[row][c] === 1 || grid[row][c] === 2) break;
            grid[row][c] = 3;
        }
        for (let row = r - 1; row >= 0; row--) {
            if (grid[row][c] === 1 || grid[row][c] === 2) break;
            grid[row][c] = 3;
        }
        for (let col = c + 1; col < n; col++) {
            if (grid[r][col] === 1 || grid[r][col] === 2) break;
            grid[r][col] = 3;
        }
        for (let col = c - 1; col >= 0; col--) {
            if (grid[r][col] === 1 || grid[r][col] === 2) break;
            grid[r][col] = 3;
        }
    };

    for (const [r, c] of guards) {
        markGuarded(r, c);
    }

    let res = 0;
    for (const row of grid) {
        for (const cell of row) {
            if (cell === 0) {
                res++;
            }
        }
    }

    return res;
}

module.exports = countUnguarded;