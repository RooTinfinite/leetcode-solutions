class Solution {
    public void inorder(TreeNode root, List<Integer> v) {
        if (root != null) {
            inorder(root.left, v);
            if (root.left == null && root.right == null) {
                v.add(root.val);
            }
            inorder(root.right, v);
        }
    }

    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> v1 = new ArrayList<>();
        List<Integer> v2 = new ArrayList<>();
        inorder(root1, v1);
        inorder(root2, v2);
        return v1.equals(v2);
    }
}