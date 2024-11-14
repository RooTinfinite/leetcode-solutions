class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if(root==None):
            return False
        
        #minus value of current node
        targetSum = targetSum-root.val
        
        #check if now a leaf node
        if (root.left == None and root.right == None):
            return targetSum == 0
        
        return self.hasPathSum(root.left, targetSum) or self.hasPathSum(root.right, targetSum)