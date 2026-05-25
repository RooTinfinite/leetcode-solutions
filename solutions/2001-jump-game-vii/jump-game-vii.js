var canReach = function (s, minJump, maxJump) {
    const n = s.length;
    const f = new Array(n).fill(0);
    const pre = new Array(n).fill(0);
    f[0] = 1;
    // since we start dynamic programming from i=minJump, we need to precompute the prefix sums for the part [0, minJump)
    for (let i = 0; i < minJump; i++) {
        pre[i] = 1;
    }
    for (let i = minJump; i < n; i++) {
        const left = i - maxJump;
        const right = i - minJump;
        if (s[i] === "0") {
            const total = pre[right] - (left <= 0 ? 0 : pre[left - 1]);
            f[i] = total !== 0 ? 1 : 0;
        }
        pre[i] = pre[i - 1] + f[i];
    }
    return f[n - 1] === 1;
};