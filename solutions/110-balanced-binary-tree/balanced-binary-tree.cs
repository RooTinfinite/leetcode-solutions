// Utility class to store information from recursive calls

public class TreeInfo {
    public int Height { get; }
    public bool Balanced { get; }

    public TreeInfo(int height, bool balanced) {
        this.Height = height;
        this.Balanced = balanced;
    }
}

public class Solution {
    // Returns whether the tree at root is balanced, along with the tree's
    // height.
    private TreeInfo IsBalancedTreeHelper(TreeNode root) {
        // An empty tree is both balanced and has a height -1.
        if (root == null) {
            return new TreeInfo(-1, true);
        }

        // Checks whether the subtrees are balanced or not.
        var left = IsBalancedTreeHelper(root.left);
        if (!left.Balanced) {
            return new TreeInfo(-1, false);
        }

        var right = IsBalancedTreeHelper(root.right);
        if (!right.Balanced) {
            return new TreeInfo(-1, false);
        }

        // The obtained height from recursive calls can also determine
        // that the current node is balanced.
        if (Math.Abs(left.Height - right.Height) < 2) {
            return new TreeInfo(Math.Max(left.Height, right.Height) + 1, true);
        }

        return new TreeInfo(-1, false);
    }

    public bool IsBalanced(TreeNode root) {
        return IsBalancedTreeHelper(root).Balanced;
    }
}