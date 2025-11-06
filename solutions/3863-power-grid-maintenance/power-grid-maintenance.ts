class DSU {
    parent: number[];

    constructor(public size: number) {
        this.parent = Array.from({ length: size }).map((_, i) => i);
    }

    join(u: number, v: number) {
        this.parent[this.find(v)] = this.find(u);
    }

    find(x: number) {
        return this.parent[x] === x
            ? x
            : (this.parent[x] = this.find(this.parent[x]));
    }
}

function processQueries(
    c: number,
    connections: number[][],
    queries: number[][],
): number[] {
    const dsu = new DSU(c + 1);

    connections.forEach(([u, v]) => {
        dsu.join(u, v);
    });

    const online = Array.from<boolean>({ length: c + 1 }).fill(true);
    const offlineCounts = Array.from<number>({ length: c + 1 }).fill(0);
    const minimumOnlineStations = new Map<number, number>();

    for (const [op, x] of queries) {
        if (op === 2) {
            online[x] = false;
            offlineCounts[x] += 1;
        }
    }

    for (let i = 1; i <= c; i++) {
        const root = dsu.find(i);
        if (!minimumOnlineStations.has(root)) {
            minimumOnlineStations.set(root, -1);
        }

        const station = minimumOnlineStations.get(root)!;
        if (online[i] === true) {
            if (station === -1 || station > i) {
                minimumOnlineStations.set(root, i);
            }
        }
    }

    const ans: number[] = [];

    for (const [op, x] of queries.reverse()) {
        const root = dsu.find(x);
        const station = minimumOnlineStations.get(root)!;

        if (op === 1) {
            if (online[x]) {
                ans.push(x);
            } else {
                ans.push(station);
            }
        }

        if (op === 2) {
            if (offlineCounts[x] > 1) {
                offlineCounts[x] -= 1;
            } else {
                online[x] = true;
                if (station === -1 || station > x) {
                    minimumOnlineStations.set(root, x);
                }
            }
        }
    }

    return ans.reverse();
}