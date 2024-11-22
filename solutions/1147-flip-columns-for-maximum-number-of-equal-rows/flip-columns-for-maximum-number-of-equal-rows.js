// JavaScript

var maxEqualRowsAfterFlips = function(mat) {
    const patFreq = new Map();
    
    for (const row of mat) {
        const pattern = row[0] === 0 
            ? row.join('')
            : row.map(bit => bit ^ 1).join('');
            
        patFreq.set(pattern, (patFreq.get(pattern) || 0) + 1);
    }
    
    return Math.max(...patFreq.values());
};