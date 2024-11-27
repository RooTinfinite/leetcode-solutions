class Solution:
    def dfs(self, tree, c, dp):
        d = dp[c] + 1
        for x in tree[c]:
            if dp[x] <= d:
                continue
            dp[x] = d
            self.dfs(tree, x, dp)
    
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        dp = [n-1-i for i in range(n)]
        tree = [[] for _ in range(n)]
        
        for i in range(n-1):
            tree[i+1].append(i)
            
        m = len(queries)
        res = [0] * m
        
        for i, q in enumerate(queries):
            a, b = q[0], q[1]
            tree[b].append(a)
            dp[a] = min(dp[a], dp[b] + 1)
            self.dfs(tree, a, dp)
            res[i] = dp[0]
            
        return res