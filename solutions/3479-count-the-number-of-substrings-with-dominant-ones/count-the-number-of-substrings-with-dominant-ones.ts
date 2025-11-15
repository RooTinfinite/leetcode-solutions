function numberOfSubstrings(s: string): number {
    const n = s.length;
    const pre: number[] = new Array(n + 1);
    pre[0] = -1;
    for (let i = 0; i < n; i++) {
        if (i === 0 || (i > 0 && s[i - 1] === "0")) {
            pre[i + 1] = i;
        } else {
            pre[i + 1] = pre[i];
        }
    }
    let res = 0;
    for (let i = 1; i <= n; i++) {
        let cnt0 = s[i - 1] === "0" ? 1 : 0;
        let j = i;
        while (j > 0 && cnt0 * cnt0 <= n) {
            const cnt1 = i - pre[j] - cnt0;
            if (cnt0 * cnt0 <= cnt1) {
                res += Math.min(j - pre[j], cnt1 - cnt0 * cnt0 + 1);
            }
            j = pre[j];
            cnt0++;
        }
    }
    return res;
}