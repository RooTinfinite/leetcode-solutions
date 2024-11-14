class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        return root and TreeNode(root.val, self.invertTree(root.right), self.invertTree(root.left))