export function minDeletions(s: string, queries: number[][]): number[] {
    const n = s.length;
    const t = new Array(n + 1).fill(0);
    const a: number[] = [];
    const sArr = Array.from(s, c => c.charCodeAt(0));

    const u = (i: number, d: number) => {
        for (i++; i <= n; i += i & -i) t[i] += d;
    };

    const q = (i: number) => {
        let r = 0;
        for (i++; i > 0; i -= i & -i) r += t[i];
        return r;
    };

    const ok = (i: number) => i >= 0 && i < n - 1 && sArr[i] !== sArr[i + 1];

    for (let i = 0; i < n - 1; i++) if (ok(i)) u(i, 1);

    for (const v of queries) {
        if (v[0] === 1) {
            const j = v[1];
            const p = ok(j - 1) ? 1 : 0;
            const c = ok(j) ? 1 : 0;
            sArr[j] ^= 3;
            const np = ok(j - 1) ? 1 : 0;
            const nc = ok(j) ? 1 : 0;
            if (np !== p) u(j - 1, np - p);
            if (nc !== c) u(j, nc - c);
        } else {
            const l = v[1];
            const r = v[2];
            a.push((r - l) - (l >= r ? 0 : q(r - 1) - q(l - 1)));
        }
    }
    return a;
}