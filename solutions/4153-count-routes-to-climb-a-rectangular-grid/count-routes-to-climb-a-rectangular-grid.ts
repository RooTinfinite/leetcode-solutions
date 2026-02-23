const numberOfRoutes = (grid: string[], d: number): number => {
    const MOD = 1e9 + 7;
    const n = grid.length;
    const m = grid[0].length;

    const maxH = Math.floor(Math.sqrt(d * d - 1));

    let dp: number[][] = Array.from({length: m}, () => [0, 0]);
    
    for (let c = 0; c < m; c++) {
        if (grid[n - 1][c] === '.') dp[c][0] = 1;
    }
    
    for (let r = n - 1; r >= 0; r--) {
        const prefix0 = new Array(m + 1).fill(0);
        for (let c = 0; c < m; c++) {
            prefix0[c + 1] = (prefix0[c] + dp[c][0]) % MOD;
        }
        
        for (let c = 0; c < m; c++) {
            if (grid[r][c] === '#') continue;
            const left = Math.max(0, c - d);
            const right = Math.min(m - 1, c + d);
            let sum = (prefix0[right + 1] - prefix0[left] + MOD) % MOD;
            sum = (sum - dp[c][0] + MOD) % MOD;
            dp[c][1] = (dp[c][1] + sum) % MOD;
        }
        
        if (r > 0) {
            const newDp: number[][] = Array.from({length: m}, () => [0, 0]);
            const prefixTotal = new Array(m + 1).fill(0);
            for (let c = 0; c < m; c++) {
                prefixTotal[c + 1] = (prefixTotal[c] + dp[c][0] + dp[c][1]) % MOD;
            }
            
            for (let c = 0; c < m; c++) {
                if (grid[r - 1][c] === '#') continue;
                const left = Math.max(0, c - maxH);
                const right = Math.min(m - 1, c + maxH);
                newDp[c][0] = (prefixTotal[right + 1] - prefixTotal[left] + MOD) % MOD;
            }
            
            dp = newDp;
        }
    }
    
    let ans = 0;
    for (let c = 0; c < m; c++) {
        if (grid[0][c] === '.') ans = (ans + dp[c][0] + dp[c][1]) % MOD;
    }
    
    return ans;
};