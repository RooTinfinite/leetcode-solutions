function shortestDistanceAfterQueries(n: number, queries: number[][]): number[] {
    const adj: number[][] = Array(n).fill(0).map((_, i) => [i + 1]);
    
    const shortestPath = (): number => {
        const q: [number, number][] = [[0, 0]]; // node, length
        const visit = new Set<number>();
        visit.add(0);
        
        while (q.length > 0) {
            const [cur, length] = q.shift()!;
            
            if (cur === n - 1) {
                return length;
            }
            
            for (const nei of adj[cur]) {
                if (!visit.has(nei)) {
                    q.push([nei, length + 1]);
                    visit.add(nei);
                }
            }
        }
        return -1;
    };
    
    const res: number[] = [];
    for (const [src, dst] of queries) {
        adj[src].push(dst);
        res.push(shortestPath());
    }
    return res;
}