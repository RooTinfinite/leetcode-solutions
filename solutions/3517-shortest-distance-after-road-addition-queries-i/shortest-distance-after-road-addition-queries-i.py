class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        
        adj = [[] for _ in range(n)]
        for i in range(n-1):
            adj[i].append(i+1)

        res = []
        for i,j in queries:
            adj[i].append(j) 
            res.append(self.bellman(adj))
            
        return res
    
    def bellman(self, adj):
        n = len(adj)
        dist = [float('inf')]*n
        dist[0] = 0

        for u in range(n):
            for v in adj[u]:
                if dist[u] + 1 < dist[v]:
                    dist[v] = dist[u] + 1
        
        return dist[-1]

