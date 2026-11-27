class Solution:
    def correctBinaryTree(self, root: TreeNode) -> TreeNode:
        q = collections.deque([root])
        p, visited = dict(), set()
        while q:
            cur = q.popleft()
            if cur in visited:
                grand_p, is_left = p[p[cur][0]]
                if is_left: grand_p.left = None
                else: grand_p.right = None    
                return root
            visited.add(cur)
            if cur.left:
                p[cur.left] = (cur, 1)
                q.append(cur.left)
            if cur.right:
                p[cur.right] = (cur, 0)
                q.append(cur.right)
        return root