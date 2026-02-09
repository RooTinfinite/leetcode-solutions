# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return self.validateHeight(root)[0]

    def validateHeight(self, node: Optional[TreeNode]) -> int:
        if node is None:
            return True, 0

        lValid, lHeight = self.validateHeight(node.left)
        rValid, rHeight = self.validateHeight(node.right)

        if lValid and rValid and abs(lHeight - rHeight) <= 1:
            return True, max(lHeight, rHeight) + 1

        return False, -1