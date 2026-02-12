function countBalanced(low: number, high: number): number {
    const O = 100;
    const MAXLEN = 20;

    function solve(s: string, tightFirst: boolean): number {
        const n = s.length;
        const memo: number[][][] = Array.from({ length: MAXLEN }, () =>
            Array.from({ length: 200 }, () => [-1, -1])
        );

        function dp(ind: number, bal: number, tight: number): number {
            if (bal < 0 || bal >= 200) return 0;
            if (ind === n) return bal === O ? 1 : 0;
            if (memo[ind][bal][tight] !== -1) return memo[ind][bal][tight];

            let res = 0;
            const lim = tight ? s.charCodeAt(ind) - 48 : 9;

            for (let d = 0; d <= lim; d++) {
                const nt = tight && d === lim ? 1 : 0;
                const nb = bal + (ind % 2 === 0 ? d : -d);
                res += dp(ind + 1, nb, nt);
            }

            memo[ind][bal][tight] = res;
            return res;
        }

        let total = 0;
        const firstLim = tightFirst ? s.charCodeAt(0) - 48 : 9;

        for (let d = 1; d <= firstLim; d++) {
            const tight = tightFirst && d === firstLim ? 1 : 0;
            total += dp(1, O + d, tight);
        }

        return total;
    }

    function len(n: number): number {
        if (n < 10) return 0;
        const s = n.toString();
        let total = 0;

        for (let l = 2; l < s.length; l++) {
            total += solve("9".repeat(l), false);
        }

        total += solve(s, true);
        return total;
    }

    return len(high) - len(low - 1);
}