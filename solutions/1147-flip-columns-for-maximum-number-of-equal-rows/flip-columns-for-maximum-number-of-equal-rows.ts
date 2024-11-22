// TypeScript

function maxEqualRowsAfterFlips(mat: number[][]): number {
    const patFreq = new Map<string, number>();
    
    for (const row of mat) {
        const pattern = row[0] === 0 
            ? row.join('')
            : row.map(bit => bit ^ 1).join('');
            
        patFreq.set(pattern, (patFreq.get(pattern) || 0) + 1);
    }
    
    return Math.max(...patFreq.values());
}