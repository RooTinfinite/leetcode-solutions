class Solution:
    def minCost(self, n, colors, edges):
        g = [[] for _ in range(n)]
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        size = [0] * n
        reds = [0] * n
        res = 0
        def dp(u, p):
            nonlocal res
            size[u] = 1
            cost = 0
            for v in g[u]:
                if v != p:
                    c = dp(v, u)
                    size[u] += size[v]
                    reds[u] += reds[v]
                    cost += min(c, reds[v])
            if colors[u] == 'R':
                reds[u] += size[u]
            else:
                cost += size[u]
            res = min(res, cost - reds[u])
            return cost
        dp(0, -1)
        return reds[0] + res