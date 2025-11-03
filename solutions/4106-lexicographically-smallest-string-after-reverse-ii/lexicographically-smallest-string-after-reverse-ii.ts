function lexSmallest(s: string): string {
    const n = s.length;
    if (n <= 1) return s;

    // Fast path: all characters identical
    if (s === s[0].repeat(n)) return s;

    let best = s;
    const smallest = Math.min(...s.split('').map(c => c.charCodeAt(0)));
    const rev = s.split('').reverse().join(''); // Cache reversed string

    // Check prefix reversals only at smallest character positions
    for (let i = 0; i < n; i++) {
        if (s.charCodeAt(i) !== smallest) continue;
        const candidate = rev.slice(n - i - 1) + s.slice(i + 1);
        if (candidate < best) best = candidate;
    }

    // Check suffix reversals (k = 1 to n)
    for (let k = 1; k <= n; k++) {
        const candidate = s.slice(0, n - k) + rev.slice(0, k);
        if (candidate < best) best = candidate;
    }

    return best;
}