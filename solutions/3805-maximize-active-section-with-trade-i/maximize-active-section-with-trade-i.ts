function maxActiveSectionsAfterTrade(s: string): number {
    const n = s.length;
    let cnt1 = 0;
    for (const c of s) {
        if (c === "1") cnt1++;
    }

    let i = 0;
    let bestGain = 0;
    let prev = -Infinity;
    let cur = 0;

    while (i < n) {
        const start = i;
        while (i < n && s[i] === s[start]) {
            i++;
        }
        if (s[start] === "0") {
            cur = i - start;
            if (prev !== -Infinity) {
                bestGain = Math.max(bestGain, prev + cur);
            }
            prev = cur;
        }
    }

    return cnt1 + bestGain;
}