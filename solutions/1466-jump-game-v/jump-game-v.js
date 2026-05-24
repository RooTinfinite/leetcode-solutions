var maxJumps = function (arr, d) {
    const n = arr.length;
    const f = new Array(n).fill(-1);

    const dfs = (id) => {
        if (f[id] !== -1) {
            return;
        }
        f[id] = 1;
        for (let i = id - 1; i >= 0 && id - i <= d && arr[id] > arr[i]; --i) {
            dfs(i);
            f[id] = Math.max(f[id], f[i] + 1);
        }
        for (let i = id + 1; i < n && i - id <= d && arr[id] > arr[i]; ++i) {
            dfs(i);
            f[id] = Math.max(f[id], f[i] + 1);
        }
    };

    for (let i = 0; i < n; ++i) {
        dfs(i);
    }

    return Math.max(...f);
};