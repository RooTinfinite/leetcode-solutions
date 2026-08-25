function isSameTree(p, q) {
    const check = (p, q) => {
        // p and q are both null
        if (p === null && q === null) return true;
        // one of p and q is null
        if (p === null || q === null) return false;
        if (p.val !== q.val) return false;
        return true;
    };
    const deq = [[p, q]];
    while (deq.length) {
        [p, q] = deq.shift();
        if (!check(p, q)) return false;
        if (p) {
            deq.push([p.left, q.left]);
            deq.push([p.right, q.right]);
        }
    }
    return true;
}