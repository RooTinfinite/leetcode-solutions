class Trie {
    child: (Trie | null)[];
    id: number;

    constructor() {
        this.child = new Array(26).fill(null);
        this.id = -1;
    }
}

function minimumCost(
    source: string,
    target: string,
    original: string[],
    changed: string[],
    cost: number[],
): number {
    const INF: number = Number.MAX_SAFE_INTEGER / 2;

    function add(node: Trie, word: string, index: { value: number }): number {
        for (const ch of word) {
            const i = ch.charCodeAt(0) - "a".charCodeAt(0);
            if (!node.child[i]) {
                node.child[i] = new Trie();
            }
            node = node.child[i]!;
        }
        if (node.id === -1) {
            node.id = ++index.value;
        }
        return node.id;
    }

    const n: number = source.length;
    const m: number = original.length;
    const root: Trie = new Trie();

    const p = { value: -1 };
    const nodeCount: number = m * 2;
    const G: number[][] = Array.from({ length: nodeCount }, () =>
        Array(nodeCount).fill(INF),
    );
    for (let i = 0; i < nodeCount; i++) {
        G[i][i] = 0;
    }

    for (let i = 0; i < m; i++) {
        const x: number = add(root, original[i], p);
        const y: number = add(root, changed[i], p);
        G[x][y] = Math.min(G[x][y], cost[i]);
    }

    const size: number = p.value + 1;
    for (let k = 0; k < size; k++) {
        for (let i = 0; i < size; i++) {
            for (let j = 0; j < size; j++) {
                G[i][j] = Math.min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }

    const f: number[] = new Array(n).fill(-1);
    for (let j = 0; j < n; j++) {
        if (j > 0 && f[j - 1] === -1) {
            continue;
        }
        const base: number = j === 0 ? 0 : f[j - 1];
        if (source[j] === target[j]) {
            if (f[j] === -1 || base < f[j]) {
                f[j] = base;
            }
        }

        let u: Trie | null = root;
        let v: Trie | null = root;
        for (let i = j; i < n; i++) {
            u = u?.child[source.charCodeAt(i) - "a".charCodeAt(0)] ?? null;
            v = v?.child[target.charCodeAt(i) - "a".charCodeAt(0)] ?? null;
            if (!u || !v) {
                break;
            }
            if (u.id !== -1 && v.id !== -1 && G[u.id][v.id] !== INF) {
                const newVal: number = base + G[u.id][v.id];
                if (f[i] === -1 || newVal < f[i]) {
                    f[i] = newVal;
                }
            }
        }
    }

    return f[n - 1];
}