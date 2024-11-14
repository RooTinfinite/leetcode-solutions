public class Solution {
    public TreeNode InvertTree(TreeNode root) {
        if (root == null) {
            return null;
        }
        
        TreeNode temp = root.left;
        root.left = InvertTree(root.right);
        root.right = InvertTree(temp);
        
        return root;
    }
}