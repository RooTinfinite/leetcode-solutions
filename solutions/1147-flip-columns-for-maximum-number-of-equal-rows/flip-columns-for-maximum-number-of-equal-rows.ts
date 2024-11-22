// TypeScript

function maxEqualRowsAfterFlips(matrix: number[][]): number {
    const count = new Map<string, number>();
    
    for (const row of matrix) {
        const key = row.map(n => row[0] ? 1 - n : n).join(',');
        count.set(key, (count.get(key) || 0) + 1);
    }
    
    return Math.max(...count.values());
}