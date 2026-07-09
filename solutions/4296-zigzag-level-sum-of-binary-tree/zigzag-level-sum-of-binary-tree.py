class Solution:
    def zigzagLevelSum(self, root: TreeNode | None) -> list[int]:

        prvLev, curLev, evenLev = [root], [], False
        ans = []

        while prvLev:
           
            sm, stop = 0, False
    
            for node in prvLev:
                if evenLev:           
                    node.left, node.right = node.right, node.left
                if node.left is None:  
                    stop = True
                else: 
                    curLev.append(node.left)
                if not stop:
                    sm+= node.val
                if node.right:
                    curLev.append(node.right)

            ans.append(sm)
            prvLev, curLev, evenLev = curLev[::-1], [], not evenLev
        
        return ans