// TypeScript

function findChampion(n: number, edges: number[][]): number {
    const incoming: number[] = new Array(n).fill(0);
    
    for (const [src, dst] of edges) {
        incoming[dst]++;
    }
    
    const champions: number[] = [];
    incoming.forEach((count, i) => {
        if (count === 0) {
            champions.push(i);
        }
    });
    
    return champions.length > 1 ? -1 : champions[0];
}