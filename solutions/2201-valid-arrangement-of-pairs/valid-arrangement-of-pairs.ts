function validArrangement(pairs: number[][]): number[][] {
    // Use object instead of Map for faster access
    const graph: Record<number, number[]> = {};
    const indegree: Record<number, number> = {};
    const outdegree: Record<number, number> = {};

    // Build graph and degrees in single pass
    for (const [from, to] of pairs) {
        graph[from] = graph[from] || [];
        graph[from].push(to);
        outdegree[from] = (outdegree[from] || 0) + 1;
        indegree[to] = (indegree[to] || 0) + 1;
    }

    // Find start node - first node with outdegree - indegree = 1
    let start = pairs[0][0];
    for (const node in outdegree) {
        if ((outdegree[node] || 0) - (indegree[node] || 0) === 1) {
            start = Number(node);
            break;
        }
    }

    const result: number[][] = [];
    
    // Hierholzer's Algorithm implementation
    function dfs(node: number): void {
        const neighbors = graph[node] = graph[node] || [];
        while (neighbors.length > 0) {
            const next = neighbors.pop()!;
            dfs(next);
            result.push([node, next]);
        }
    }

    dfs(start);
    return result.reverse();
}