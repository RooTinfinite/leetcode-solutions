class Solution:
    def longestConsecutive(self, node: Optional[TreeNode], last_val = -inf, curr_seq = 1) -> int:
        if not node:
            return 0
        
        if node.val == last_val + 1:
            curr_seq += 1
        else:
            curr_seq = 1
            
        l = self.longestConsecutive(node.left, node.val, curr_seq)
        r = self.longestConsecutive(node.right, node.val, curr_seq)
        
        return max(curr_seq, l, r)