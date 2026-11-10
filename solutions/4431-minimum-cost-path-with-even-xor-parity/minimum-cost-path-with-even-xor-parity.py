class Solution:
    def minActivationCost(self, edges: list[list[int]], values: list[int]) -> int:
        """
        :type edges: List[List[int]]
        :type values: List[int]
        :rtype: int
        """
        ret = float('inf')
        n = len(values)
        parity = [val.bit_count() & 1 > 0 for val in values] 
        adj = [[] for _ in range(n)]
        
        for u, v, w in edges:
            
            if parity[u] == parity[v]: # one edge paths between two nodes with same parity
                ret = min(ret, w)
            elif not parity[u]:  # if U is even parity and v odd, append the weight to u
                adj[u].append(w)
            else:  # vice versa for v
                adj[v].append(w)
                
        # so now if two edges from odd parity go through even parity r, 
        # take the two cheapest through r
        for r in range(n):
            if len(adj[r]) >= 2:
                m1,m2 = inf,inf
                for x in adj[r]:
                    if x<m1: m1,m2 = x,m1
                    elif x<m2: m2=x
                ret = min(ret, m1+m2)
                
        return -1 if ret == float('inf') else ret