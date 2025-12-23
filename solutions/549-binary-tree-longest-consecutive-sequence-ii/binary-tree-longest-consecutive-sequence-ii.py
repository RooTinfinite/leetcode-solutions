class Solution:
    def __init__(self):
        self.res = 0
        
    def dfs(self, node):
        if not node:
            return (0, 0)
        
        incr, decr = 1, 1
        
        lincr, ldecr = self.dfs(node.left)
        if node.left and node.left.val - node.val == 1:
            incr += lincr
        elif node.left and node.val - node.left.val == 1:
            decr += ldecr
        
        rincr, rdecr = self.dfs(node.right)
        if node.right and node.right.val - node.val == 1:
            incr = max(incr, rincr + 1)
        elif node.right and node.val - node.right.val == 1:
            decr = max(decr, rdecr + 1)
            
        self.res = max(self.res, incr + decr - 1) # incr and decr consit curent node => we must remove cur node count (without -1 this sum will consider twice)
        
        return (incr, decr)
    
    def longestConsecutive(self, root: Optional[TreeNode]) -> int:
        self.dfs(root)
        
        return self.res