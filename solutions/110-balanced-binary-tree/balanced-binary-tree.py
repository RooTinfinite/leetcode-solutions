class Solution:
    # Compute the tree's height via recursion
    def height(self, root: TreeNode) -> int:
        # An empty tree has height -1
        if not root:
            return -1
        return 1 + max(self.height(root.left), self.height(root.right))

    def isBalanced(self, root: TreeNode) -> bool:
        # An empty tree satisfies the definition of a balanced tree
        if not root:
            return True

        # Check if subtrees have height within 1. If they do, check if the
        # subtrees are balanced
        return (
            abs(self.height(root.left) - self.height(root.right)) < 2
            and self.isBalanced(root.left)
            and self.isBalanced(root.right)
        )