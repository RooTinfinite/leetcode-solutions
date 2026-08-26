var shortestBeautifulSubstring = function (s, k) {
    for (let m = k; m <= s.length; m++) {
        let ans = "";
        for (let i = m; i <= s.length; i++) {
            const t = s.slice(i - m, i);
            if (
                (!ans || t < ans) &&
                [...t].filter((c) => c === "1").length === k
            ) {
                ans = t;
            }
        }
        if (ans) return ans;
    }
    return "";
};