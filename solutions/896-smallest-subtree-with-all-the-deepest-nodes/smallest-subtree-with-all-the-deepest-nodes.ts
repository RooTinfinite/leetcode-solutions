function subtreeWithAllDeepest(root: TreeNode | null): TreeNode | null {
    function dfs(node: TreeNode | null): [number, TreeNode | null] {
        if (!node) return [0, null];
        const [ld, ln] = dfs(node.left);
        const [rd, rn] = dfs(node.right);
        if (ld > rd) return [ld + 1, ln];
        if (rd > ld) return [rd + 1, rn];
        return [ld + 1, node];
    }
    return dfs(root)[1];
}