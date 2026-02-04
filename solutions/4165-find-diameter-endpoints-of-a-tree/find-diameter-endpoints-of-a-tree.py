class Solution:
    def findSpecialNodes(self, n: int, edges: List[List[int]]) -> str:

        @lru_cache(None)
        def dist(node, parent = None):
            mx = lambda x,y: x if x > y else y
            res = 1 
            for neighbor in graph[node]:
                if neighbor == parent: continue
                res = mx(res, dist(neighbor, node) + 1)
            return res


        ans = ['0'] * n
        graph = [[] for _ in range(n)]

        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        path = [dist(i) for i in range(n)]        
        diam = max(path)
        for i in range(n):
            if path[i] == diam: ans[i] = '1'

        return ''.join(ans)