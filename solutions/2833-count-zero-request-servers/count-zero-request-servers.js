var countServers = function (n, logs, x, queries) {
    logs.sort((a, b) => a[1] - b[1]);

    const m = queries.length;
    const ids = Array.from({ length: m }, (_, i) => i);
    ids.sort((i, j) => queries[i] - queries[j]);

    const ans = new Array(m).fill(0);
    const cnt = new Array(n + 1).fill(0);
    let left = 0,
        right = 0,
        active = 0;

    for (const i of ids) {
        const q = queries[i];
        while (right < logs.length && logs[right][1] <= q) {
            const id = logs[right++][0];
            if (cnt[id]++ === 0) {
                ++active;
            }
        }
        while (left < right && logs[left][1] < q - x) {
            const id = logs[left++][0];
            if (--cnt[id] === 0) {
                --active;
            }
        }
        ans[i] = n - active;
    }
    return ans;
};