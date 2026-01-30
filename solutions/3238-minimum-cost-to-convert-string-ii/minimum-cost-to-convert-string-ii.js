class Trie {
    constructor() {
        this.child = new Array(26).fill(null);
        this.id = -1;
    }
}

function minimumCost(source, target, original, changed, cost) {
    const INF = Number.MAX_SAFE_INTEGER / 2;

    function add(node, word, index) {
        for (const ch of word) {
            const i = ch.charCodeAt(0) - "a".charCodeAt(0);
            if (!node.child[i]) {
                node.child[i] = new Trie();
            }
            node = node.child[i];
        }
        if (node.id === -1) {
            node.id = ++index.value;
        }
        return node.id;
    }

    const n = source.length;
    const m = original.length;
    const root = new Trie();

    const p = { value: -1 };
    const nodeCount = m * 2;
    const G = Array.from({ length: nodeCount }, () =>
        Array(nodeCount).fill(INF),
    );
    for (let i = 0; i < nodeCount; i++) {
        G[i][i] = 0;
    }
    for (let i = 0; i < m; i++) {
        const x = add(root, original[i], p);
        const y = add(root, changed[i], p);
        G[x][y] = Math.min(G[x][y], cost[i]);
    }

    const size = p.value + 1;
    for (let k = 0; k < size; k++) {
        for (let i = 0; i < size; i++) {
            for (let j = 0; j < size; j++) {
                G[i][j] = Math.min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }

    const f = new Array(n).fill(-1);
    for (let j = 0; j < n; j++) {
        if (j > 0 && f[j - 1] === -1) {
            continue;
        }
        const base = j === 0 ? 0 : f[j - 1];
        if (source[j] === target[j]) {
            if (f[j] === -1 || base < f[j]) {
                f[j] = base;
            }
        }

        let u = root;
        let v = root;
        for (let i = j; i < n; i++) {
            u = u.child[source.charCodeAt(i) - "a".charCodeAt(0)];
            v = v.child[target.charCodeAt(i) - "a".charCodeAt(0)];
            if (!u || !v) {
                break;
            }
            if (u.id !== -1 && v.id !== -1 && G[u.id][v.id] !== INF) {
                const newVal = base + G[u.id][v.id];
                if (f[i] === -1 || newVal < f[i]) {
                    f[i] = newVal;
                }
            }
        }
    }

    return f[n - 1];
}