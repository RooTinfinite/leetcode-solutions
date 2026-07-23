import heapq

class Solution:
    def shortestPath(self, n, edges, labels, k):
        INF = float('inf')

        adj = [[] for _ in range(n)]
        for u, v, w in edges:
            adj[u].append((v, w))

        dist = [[INF] * (k + 1) for _ in range(n)]
        dist[0][1] = 0

        # (distance, node, cnt)
        pq = [(0, 0, 1)]

        while pq:
            d, u, cur = heapq.heappop(pq)
            if d != dist[u][cur]:
                continue

            for v, w in adj[u]:
                newcur = cur + 1 if labels[v] == labels[u] else 1
                if newcur > k:
                    continue
                if dist[v][newcur] > d + w:
                    dist[v][newcur] = d + w
                    heapq.heappush(pq, (dist[v][newcur], v, newcur))

        ans = min(dist[n - 1][1:k + 1])
        return -1 if ans == INF else ans