function longestSubsequenceRepeatedK(s: string, k: number): string {
    const freq: Record<string, number> = {};
    for (const c of s) freq[c] = (freq[c] || 0) + 1;

    const candidate = Object.keys(freq)
        .filter((c) => freq[c] >= k)
        .sort()
        .reverse();
    const q: string[] = [...candidate];
    let ans = "";
    while (q.length > 0) {
        const curr = q.shift()!;
        if (curr.length > ans.length) {
            ans = curr;
        }
        // generate the next candidate string
        for (const c of candidate) {
            const next = curr + c;
            if (isKRepeated(s, next, k)) q.push(next);
        }
    }

    return ans;
}

function isKRepeated(s: string, pattern: string, k: number): boolean {
    let i = 0,
        matched = 0;
    for (const c of s) {
        if (c === pattern[i]) {
            i++;
            if (i === pattern.length) {
                i = 0;
                matched++;
                if (matched === k) {
                    return true;
                }
            }
        }
    }

    return false;
}