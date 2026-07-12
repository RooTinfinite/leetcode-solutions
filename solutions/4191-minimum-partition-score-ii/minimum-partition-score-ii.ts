function minPartitionScore(nums: number[], k: number): number {
    const n = nums.length;
    const pref = new Array<number>(n + 1).fill(0);
    for (let i = 0; i < n; i++) pref[i + 1] = pref[i] + nums[i];

    const total = pref[n];

    type Line = { m: number; b: number; c: number };

    const run = (penalty: number): { dp: number; cnt: number } => {
        const dp = new Array<number>(n + 1).fill(0);
        const cnt = new Array<number>(n + 1).fill(0);
        const hull: Line[] = [];

        const value = (line: Line, x: number): number => line.m * x + line.b;

        const better = (a: Line, b: Line, x: number): boolean => {
            const va = value(a, x);
            const vb = value(b, x);
            return va < vb || (va === vb && a.c > b.c);
        };

        const bad = (a: Line, b: Line, c: Line): boolean => {
            return (b.b - a.b) / (a.m - b.m) >= (c.b - b.b) / (b.m - c.m);
        };

        const addLine = (line: Line): void => {
            while (hull.length >= 2 && bad(hull[hull.length - 2], hull[hull.length - 1], line)) {
                hull.pop();
            }
            hull.push(line);
        };

        addLine({ m: 0, b: 0, c: 1 });

        for (let i = 1; i <= n; i++) {
            const x = pref[i];

            while (hull.length >= 2 && !better(hull[0], hull[1], x)) {
                hull.shift();
            }

            const best = hull[0];
            dp[i] = value(best, x) + x * x + penalty;
            cnt[i] = best.c;

            addLine({
                m: -2 * x,
                b: dp[i] + x * x,
                c: cnt[i] + 1
            });
        }

        return { dp: dp[n], cnt: cnt[n] };
    };

    let lo = -total * total;
    let hi = total * total;

    while (lo < hi) {
        const mid = Math.floor((lo + hi + 1) / 2);
        if (run(mid).cnt >= k) lo = mid;
        else hi = mid - 1;
    }

    const res = run(lo).dp - lo * k;
    return Math.round((res + total) / 2);
}