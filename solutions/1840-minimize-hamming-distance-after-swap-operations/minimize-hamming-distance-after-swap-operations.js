class UnionFind {
    constructor(n) {
        this.fa = new Array(n);
        this.rank = new Array(n).fill(0);
        for (let i = 0; i < n; i++) {
            this.fa[i] = i;
        }
    }

    find(x) {
        if (this.fa[x] !== x) {
            this.fa[x] = this.find(this.fa[x]);
        }
        return this.fa[x];
    }

    union(x, y) {
        x = this.find(x);
        y = this.find(y);
        if (x === y) return;
        if (this.rank[x] < this.rank[y]) {
            [x, y] = [y, x];
        }
        this.fa[y] = x;
        if (this.rank[x] === this.rank[y]) {
            this.rank[x]++;
        }
    }
}

var minimumHammingDistance = function (source, target, allowedSwaps) {
    const n = source.length;
    const uf = new UnionFind(n);

    for (const [a, b] of allowedSwaps) {
        uf.union(a, b);
    }

    const sets = new Map();
    for (let i = 0; i < n; i++) {
        const f = uf.find(i);
        if (!sets.has(f)) {
            sets.set(f, new Map());
        }
        const cnt = sets.get(f);
        cnt.set(source[i], (cnt.get(source[i]) || 0) + 1);
    }

    let ans = 0;
    for (let i = 0; i < n; i++) {
        const f = uf.find(i);
        const cnt = sets.get(f);
        const count = cnt.get(target[i]) || 0;
        if (count > 0) {
            cnt.set(target[i], count - 1);
        } else {
            ans++;
        }
    }
    return ans;
};