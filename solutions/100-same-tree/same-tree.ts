function isSameTree(p: TreeNode | null, q: TreeNode | null): boolean {
    const check = (p: TreeNode | null, q: TreeNode | null): boolean => {
        if (p === null && q === null) return true;
        if (p === null || q === null) return false;
        if (p.val !== q.val) return false;
        return true;
    };
    const deq: [TreeNode | null, TreeNode | null][] = [[p, q]];
    while (deq.length) {
        [p, q] = deq.shift() as [TreeNode | null, TreeNode | null];
        if (!check(p, q)) return false;
        if (p) {
            deq.push([p.left, q?.left] as [TreeNode | null, TreeNode | null]);
            deq.push([p.right, q?.right] as [TreeNode | null, TreeNode | null]);
        }
    }
    return true;
}