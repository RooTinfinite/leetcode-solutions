# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.res = None
        def helper(node: 'TreeNode') -> 'TreeNode':
            if not node:
                return None
            left_node = helper(node.left)
            right_node = helper(node.right)
            if not self.res and p in [left_node, right_node, node] and q in [left_node, right_node, node]:
                self.res = node
                return node
            return left_node or right_node or (node if node in [p,q] else None)
        
        helper(root)
        return self.res
# TC: O(N) where N is the total number of nodes in the tree
# AS: O(N) call stacks for screwed tree