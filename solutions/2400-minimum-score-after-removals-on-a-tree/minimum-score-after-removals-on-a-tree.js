var minimumScore = function (nums, edges) {
    const n = nums.length;
    const e = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) {
        e[u].push(v);
        e[v].push(u);
    }

    let sum = 0;
    for (const x of nums) {
        sum ^= x;
    }
    let res = Infinity;

    function dfs2(x, f, oth, anc) {
        let son = nums[x];
        for (const y of e[x]) {
            if (y === f) {
                continue;
            }
            son ^= dfs2(y, x, oth, anc);
        }
        if (f === anc) {
            return son;
        }
        res = Math.min(res, calc(oth, son, sum ^ oth ^ son));
        return son;
    }

    function dfs(x, f) {
        let son = nums[x];
        for (const y of e[x]) {
            if (y === f) {
                continue;
            }
            son ^= dfs(y, x);
        }

        for (const y of e[x]) {
            if (y === f) {
                dfs2(y, x, son, x);
            }
        }
        return son;
    }

    dfs(0, -1);
    return res;
};

function calc(part1, part2, part3) {
    return (
        Math.max(part1, Math.max(part2, part3)) -
        Math.min(part1, Math.min(part2, part3))
    );
}