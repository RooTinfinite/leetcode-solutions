class Solution:
    def minimumFlips(self, n: int, edges: List[List[int]], start: str, target: str) -> List[int]:
        adj = [[] for _ in range(n)]
        ind = 0
        for u,v in edges:
            adj[u].append((v, ind))
            adj[v].append((u, ind))
            ind +=1

        diff = []
        for i in range(n):
            diff.append(int(start[i]) ^ int(target[i]))

        res = []
        def dfs( u , p , ind):
            c_diff = diff[u]
            for v , idx in adj[u]:
                if v == p:
                    continue

                call = dfs(v , u , idx)
                if call:
                    c_diff ^=1
            if c_diff == 1:
                if p == -1:
                    return True
                res.append(ind)
                return True
            return False

        solve = dfs(0,-1,-1)
        if solve:
            return [-1]

        res.sort()
        return res