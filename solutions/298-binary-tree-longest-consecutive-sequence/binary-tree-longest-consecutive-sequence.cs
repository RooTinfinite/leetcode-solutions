public class Solution {
    public int LongestConsecutive(TreeNode root) 
    {
        return Dfs(root, root.val, 0);
    }

    private int Dfs(TreeNode node, int pValue, int count)
    {
        if (node == null)
            return count;

        count = 1 + (node.val == pValue + 1 ? count : 0);
        return Math.Max(count, Math.Max(Dfs(node.left, node.val, count), Dfs(node.right, node.val, count)));
    }
}