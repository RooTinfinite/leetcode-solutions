const MX = 1000001;
const factors = Array.from({ length: MX }, () => []);
for (let i = 2; i < MX; i++) {
    if (factors[i].length === 0) {
        for (let j = i; j < MX; j += i) {
            factors[j].push(i);
        }
    }
}

var minJumps = function (nums) {
    const n = nums.length;
    const edges = new Map();
    for (let i = 0; i < n; i++) {
        for (const p of factors[nums[i]]) {
            if (!edges.has(p)) edges.set(p, []);
            edges.get(p).push(i);
        }
    }
    let res = 0;
    const seen = new Array(n).fill(false);
    seen[0] = true;
    let q = [0];
    while (true) {
        let q2 = [];
        for (const i of q) {
            if (i === n - 1) return res;
            if (i > 0 && !seen[i - 1]) {
                seen[i - 1] = true;
                q2.push(i - 1);
            }
            if (i < n - 1 && !seen[i + 1]) {
                seen[i + 1] = true;
                q2.push(i + 1);
            }
            if (factors[nums[i]].length === 1) {
                const p = nums[i];
                const list = edges.get(p);
                if (list) {
                    for (const j of list) {
                        if (!seen[j]) {
                            seen[j] = true;
                            q2.push(j);
                        }
                    }
                    edges.set(p, []);
                }
            }
        }
        q = q2;
        res++;
    }
};