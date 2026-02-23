function findMaxVal(n: number, r: number[][], diff: number[]): number {
    let idxObj = {};

    // fill basic 
    for (let i = 0; i < r.length; i++) {
        let [idx, limit] = r[i];
        idxObj[idx] = limit;
    }

    // extend 
    for (let i = n - 2; i >= 0; i--) {
        let nextLimit = (idxObj[i + 1] || Infinity);
        let maxJump = diff[i];

        let currLimit = Math.min((idxObj[i] || Infinity), nextLimit + maxJump)
        idxObj[i] = currLimit;
    }

    let max = 0;
    let curr = 0;

    for (let i = 0; i < n - 1; i++) {
        let jump = diff[i];
        let limit = idxObj[i + 1] || Infinity;

        curr = Math.min(limit, curr + jump);
        max = Math.max(max, curr);
    }

    return max;
};