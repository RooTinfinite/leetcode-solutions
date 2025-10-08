class Solution:
    def maxWeight(self, n: int, edges: List[List[int]], k: int, t: int) -> int:
        adj = [[] for _ in range(n)]
        for u, v, wt in edges:
            adj[u].append((v, wt))

        dp = [[set() for _ in range(k + 1)] for _ in range(n)]
        for u in range(n):
            dp[u][0].add(0)

        for e in range(k):
            for u in range(n):
                for v, wt in adj[u]:
                    for w in dp[u][e]:
                        new_w = w + wt
                        if new_w < t:
                            dp[v][e + 1].add(new_w)

        ans = -1
        for u in range(n):
            if dp[u][k]:
                ans = max(ans, max(dp[u][k]))
        return ans