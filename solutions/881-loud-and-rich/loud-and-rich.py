class Solution:
    def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:
        
        def dfs(v, p, graph, visited):
            visited[v] = p
            for u in graph[v]:
                if visited[u] is False:
                    dfs(u,p,graph,visited)
            
        n = len(quiet)

        graph = [[] for _ in range(n)]

        for i,j in richer:
            graph[i].append(j)

        visited = [False] * n
        
        hp = []
        for q in range(n):
            heapq.heappush(hp, (quiet[q], q))
        
        while hp:
            q,v = heapq.heappop(hp)
            if visited[v] is False:
                dfs(v,v,graph,visited)
        
        return visited
            