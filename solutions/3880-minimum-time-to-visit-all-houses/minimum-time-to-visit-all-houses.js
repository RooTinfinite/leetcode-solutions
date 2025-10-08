/**
 * @param {number[]} forward
 * @param {number[]} backward
 * @param {number[]} queries
 * @return {number}
 */
var minTotalTime = function(forward, backward, queries) {
    const n = forward.length;
    const fwd = new Float64Array(n+1);
    const bwd = new Float64Array(n+1);
    for (let i = 1; i <= n; i++) {
        fwd[i] = fwd[i-1] + forward[i-1];
    }
    for (let i = 1; i < n; i++) {
        bwd[i] = bwd[i-1] + backward[i];
    }
    bwd[n] = bwd[n-1] + backward[0];
    const totalFwd = fwd[n], totalBwd = bwd[n];

    let ans = 0;
    let cur = 0;
    const m = queries.length;
    for (let i = 0; i < m; i++) {
        const v = queries[i];
        const u = cur;
        // clockwise distance
        let cw = u <= v
            ? fwd[v] - fwd[u]
            : totalFwd - (fwd[u] - fwd[v]);
        // counter‐clockwise distance
        let ccw = u >= v
            ? bwd[u] - bwd[v]
            : totalBwd - (bwd[v] - bwd[u]);
        ans += (cw < ccw ? cw : ccw);
        cur = v;
    }
    return ans;
};