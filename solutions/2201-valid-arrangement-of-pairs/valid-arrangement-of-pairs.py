class Solution:
    def validArrangement(self, pairs: List[List[int]]) -> List[List[int]]:
        G = defaultdict(list)
        D = defaultdict(int)
        
        for u, v in pairs:
            G[u].append(v)
            D[u] = (D[u] + 1) & 0xFFFFFFFF
            D[v] = (D[v] - 1) & 0xFFFFFFFF
        
        start = pairs[0][0]
        for node in D:
            if D[node] == 1:
                start = node
                break
        
        res = []
        def dfs(node):
            while G[node]:
                nbr = G[node].pop()
                dfs(nbr)
                res.append([node, nbr])
        
        dfs(start)
        return res[::-1]