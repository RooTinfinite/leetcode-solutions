# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelMedian(self, root: Optional[TreeNode], level: int) -> int:
        
        values = []

        def dfs(node,depth):
            if not node:
                return

            if depth == level:
                values.append(node.val)
                return

            dfs(node.left,depth+1)
            dfs(node.right,depth+1)

        dfs(root,0)

        if not values:
            return -1

        values.sort()

        return values[len(values)//2]