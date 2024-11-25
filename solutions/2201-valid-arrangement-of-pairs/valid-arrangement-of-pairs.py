class Solution:
    def validArrangement(self, pairs: List[List[int]]) -> List[List[int]]:
        G = defaultdict(list)
        D = defaultdict(int)
        
        # Direct graph building
        for u, v in pairs:
            G[u].append(v)
            D[u] += 1
            D[v] -= 1
        
        # Find start node
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