function minCost(n: number, edges: number[][]): number {
    const g: [number, number][][] = Array.from({ length: n }, () => []);
    for (const e of edges) {
        const [x, y, w] = e;
        g[x].push([y, w]);
        g[y].push([x, 2 * w]);
    }

    const dist: number[] = Array(n).fill(Infinity);
    const visited: boolean[] = Array(n).fill(false);
    dist[0] = 0;
    const pq = new PriorityQueue<[number, number]>((a, b) => {
        return a[0] < b[0] ? -1 : 1;
    });
    pq.enqueue([0, 0]);

    while (!pq.isEmpty()) {
        const [currentDist, x] = pq.dequeue()!;
        if (x === n - 1) {
            return currentDist;
        }
        if (visited[x]) {
            continue;
        }
        visited[x] = true;

        for (const [y, w] of g[x]) {
            if (currentDist + w < dist[y]) {
                dist[y] = currentDist + w;
                pq.enqueue([dist[y], y]);
            }
        }
    }

    return -1;
}