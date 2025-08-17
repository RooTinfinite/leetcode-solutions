class Solution:
    def networkBecomesIdle(self, edges: List[List[int]], patience: List[int]) -> int:
        
        def time(dis_pat: tuple)-> int:                     # <-- 1
            dis, pat = dis_pat
            msgs = (dis - 1) // pat
            return msgs * pat + dis + 1


        dist, graph = [-1]*len(patience), defaultdict(list)
        dist[0] = 0 
        queue = deque([0])
           
        for u, v in edges: 
            graph[v].append(u)
            graph[u].append(v)

        while queue:                                        # <-- 2
            node = queue.popleft()

            for neighbor in graph[node]:
               
                if dist[neighbor] == -1:
                    dist[neighbor] = dist[node] + 2
                    queue.append(neighbor)

        return max(map(time, zip(dist[1:], patience[1:])))  # <-- 3