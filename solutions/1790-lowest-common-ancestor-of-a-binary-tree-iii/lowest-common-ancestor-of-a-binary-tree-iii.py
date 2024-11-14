"""
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
"""

class Solution:
    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        p_copy, q_copy = p, q
        while p_copy != q_copy:
            if q_copy:
                q_copy = q_copy.parent
            else:
                q_copy = p
            if p_copy:
                p_copy = p_copy.parent
            else:
                p_copy = q
        return p_copy
            