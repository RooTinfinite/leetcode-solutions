/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int maxLen =0;
    public int longestConsecutive(TreeNode root) {
        
        if (root == null) return 0;

        if (root.left == null && root.right==null) return 1;

        conSeq(root);

        return maxLen;
    }

    private int conSeq(TreeNode root)
    {
        if (root == null) return 0;

        if (root.left == null && root.right == null) return 1;

        int left=0, right=0;
        int leftLen =0;
        int rightLen =0;
        int currLen =0;
        if (root.left != null)
        {
            left = conSeq(root.left);

            if (root.left.val - root.val == 1)
            {
                leftLen = left + 1;
            }else
            {
                leftLen = 1;
            }
        }

        if (root.right != null)
        {
            right = conSeq(root.right);

            if (root.right.val - root.val == 1)
            {
                rightLen = right + 1;
            }else
            {
                rightLen = 1;
            }
        }

        currLen = Math.max(currLen, Math.max(rightLen, leftLen));

        maxLen = Math.max(maxLen, currLen);

        return currLen;
    }
}