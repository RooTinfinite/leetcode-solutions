/**
 * @param {character[][]} grid
 * @return {number[]}
 */
var lastVisitedCell = function(grid) {
    const m = grid.length;
    const n = grid[0].length;
    const visited = Array.from({ length: m }, () => Array(n).fill(false));
    
    let r = 0, c = 0;
    visited[0][0] = true;
    
    while (true) {
        const dir = grid[r][c];
        let nr = r, nc = c;
        
        if (dir === 'U') nr--;
        else if (dir === 'D') nr++;
        else if (dir === 'L') nc--;
        else if (dir === 'R') nc++;
        
        // Stop if out of bounds or already visited
        if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc]) {
            return [r, c];
        }
        
        visited[nr][nc] = true;
        r = nr;
        c = nc;
    }
};