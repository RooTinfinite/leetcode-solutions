import heapq
from typing import List

class Solution:
    def minTimeMaxPower(self, n: int, edges: List[List[int]], p: int,
                        cost: List[int], s: int, t: int) -> List[int]:
        inf = float('inf')
        adj = [[] for _ in range(n)]
        for u, v, w in edges:
            adj[u].append((v, w))
        ans = [-1, -1]
        dist = [[inf] * (p + 1) for _ in range(n)]
        dist[s][p] = 0
        # priority queue stores (time, node, remaining power)
        pq = [(0, s, p)]
        best, bestp = -1, -1
        while pq:
            time, u, remp = heapq.heappop(pq)
            if time != dist[u][remp]:
                continue
            if best != -1 and time > best:
                break
            if u == t:
                if best == -1:
                    best = time
                bestp = max(remp, bestp)
                continue
            if remp < cost[u]:
                continue
            nxtp = remp - cost[u]
            for v, w in adj[u]:
                ntime = time + w
                if ntime < dist[v][nxtp]:
                    dist[v][nxtp] = ntime
                    heapq.heappush(pq, (ntime, v, nxtp))
        ans[0] = best
        ans[1] = bestp
        return ans