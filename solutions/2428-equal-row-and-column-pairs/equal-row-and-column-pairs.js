/**
 * @param {number[][]} grid
 * @return {number}
 */
var equalPairs = function(grid) {

    const n = grid.length
    let count = 0
    const rows = new Map()

    for(let r = 0; r < n; r++){
        const row = JSON.stringify(grid[r])
        rows.set(row, 1 + (rows.get(row) || 0))
    }

    for(let c = 0; c < n; c++){
        const col = JSON.stringify(grid.map(row => row[c]))
        count += (rows.get(col) || 0)
    }
    
    return count
};