public class Solution {
    public bool HasPathSum(TreeNode root, int targetSum) {
        if (root == null) {
            return false;
        }

        //minus value of current node
        targetSum -= root.val;
        
        //check if now a leaf node
        if (root.left == null && root.right == null) {
            return targetSum == 0;
        }

        return HasPathSum(root.left, targetSum) || HasPathSum(root.right, targetSum);
    }
}