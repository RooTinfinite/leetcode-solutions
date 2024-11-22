// JavaScript

var maxEqualRowsAfterFlips = function(matrix) {
    const count = new Map();
    
    for (const row of matrix) {
        const key = row.map(n => row[0] ? 1 - n : n).join(',');
        count.set(key, (count.get(key) || 0) + 1);
    }
    
    return Math.max(...count.values());
};