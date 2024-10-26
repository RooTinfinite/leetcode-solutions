class Solution:
    def treeQueries(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:
        heights = [0] * 50000
        d = [0] * 100001
        l = [0] * 100001
        r = [0] * 100001
        len_leaves = 0
        
        def search(p: TreeNode, h: int) -> None:
            nonlocal len_leaves
            d[p.val] = h
            
            if not p.left and not p.right:
                heights[len_leaves] = h
                l[p.val] = r[p.val] = len_leaves
                len_leaves += 1
                return
            
            l[p.val] = len_leaves
            
            if p.left:
                search(p.left, h + 1)
            if p.right:
                search(p.right, h + 1)
                
            r[p.val] = len_leaves - 1
        
        search(root, 0)
        
        n = len_leaves
        maxl = [0] * n
        maxr = [0] * n
        
        for i in range(1, n):
            maxl[i] = max(maxl[i-1], heights[i-1])
            maxr[n-i-1] = max(maxr[n-i], heights[n-i])
        
        ret = []
        
        for query in queries:
            maxxl = maxl[l[query]]
            maxxr = maxr[r[query]]
            ret.append(max(max(maxxl, maxxr), d[query]-1))
        
        return ret