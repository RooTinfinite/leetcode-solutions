function minWindow(s: string, t: string): string {
    if (s.length === 0 || t.length === 0) {
        return "";
    }
    let dictT: Record<string, number> = {};
    for (let i = 0; i < t.length; i++) {
        let count = dictT[t.charAt(i)] || 0;
        dictT[t.charAt(i)] = count + 1;
    }
    let required = Object.keys(dictT).length;
    let filteredS: [number, string][] = [];
    for (let i = 0; i < s.length; i++) {
        let c = s.charAt(i);
        if (dictT.hasOwnProperty(c)) {
            filteredS.push([i, c]);
        }
    }
    let l = 0,
        r = 0,
        formed = 0;
    let windowCounts: Record<string, number> = {};
    let ans: number[] = [-1, 0, 0];
    while (r < filteredS.length) {
        let c = filteredS[r][1];
        let count = windowCounts[c] || 0;
        windowCounts[c] = count + 1;
        if (dictT.hasOwnProperty(c) && windowCounts[c] === dictT[c]) {
            formed++;
        }
        while (l <= r && formed === required) {
            c = filteredS[l][1];
            let end = filteredS[r][0];
            let start = filteredS[l][0];
            if (ans[0] === -1 || end - start + 1 < ans[0]) {
                ans[0] = end - start + 1;
                ans[1] = start;
                ans[2] = end;
            }
            windowCounts[c] = windowCounts[c] - 1;
            if (dictT.hasOwnProperty(c) && windowCounts[c] < dictT[c]) {
                formed--;
            }
            l++;
        }
        r++;
    }
    return ans[0] === -1 ? "" : s.substring(ans[1], ans[2] + 1);
}